// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
	  if (sz > 0 && sz <= MAX_VECTOR_SIZE)
		  pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
	  else throw exception("(!) [error] (!)\n Negative size (or) Zero size (or) too Big size ");
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
	if (s>MAX_VECTOR_SIZE) throw exception("Size is more then it has to be")
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  TDynamicVector(const TDynamicVector& v)
  {
	  sz = v.sz;
	  pMem = new T[sz];
	  std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
	  pMem = nullptr;
	  swap(*this, v);
  }
  ~TDynamicVector()
  {
	  delete[] pMem;
  }

  size_t size() const noexcept { return sz; }




  //----------------------------------------------------------------------------

  TDynamicVector& operator=(const TDynamicVector& v)
  {
	  if (this == &v) return *this;
	  
	  if (sz != v.sz)
	  {
		  T* p = new T[v.sz];
		  delete[] pMem;
		  sz = v.sz;
		  pMem = p;
	  }
	  copy(v.pMem, v.pMem + sz, pMem);
	  return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
	  delete[] pMem;
	  pMem = nullptr;
	  sz = 0;
	  swap(*this, v);
	  return *this;
  }

  

  // индексация
  T& operator[](size_t ind)
  {
		  return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
		  return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
	  if (ind >= 0 && ind < sz)
		  return pMem[ind];
	  else throw exception(" (!) [error] (!)\n index out of range");
  }
  const T& at(size_t ind) const
  {
	  if (ind >= 0 && ind < sz)
		  return pMem[ind];
	  else throw exception(" (!) [error] (!)\n index out of range");
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
	  if (sz != v.sz) return false;
	  for (size_t i = 0; i < sz; i++)
	  {
		  if (pMem[i] != v.pMem[i])
			  return false;
	  }
	  return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
	  return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
	  TDynamicVector tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] + val;
	  }
	  return tmp;
  }
  TDynamicVector operator-(T val)
  {
	  TDynamicVector tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] - val;
	  }
	  return tmp;
  }
  TDynamicVector operator*(T val)
  {
	  TDynamicVector tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] * val;
	  }
	  return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
	  if (v.sz != sz) throw exception("Vectors have different sizes");
	  TDynamicVector tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] + v.pMem[i];
	  }
	  return tmp;
  }

  TDynamicVector operator-(const TDynamicVector& v)
  {
	  if (v.sz != sz) throw exception("Vectors have different sizes");
	  TDynamicVector tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] - v.pMem[i];
	  }
	  return tmp;
  }

  T operator*(const TDynamicVector& v)
  {
	  if (v.sz != sz) throw exception("Vectors have different sizes");
	  T Summ = NULL;
	  for (size_t i = 0; i < sz; i++)
	  {
		  Summ += pMem[i] * v.pMem[i];
	  }
	  return Summ;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }



};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
	  if (s > 0 && s <= MAX_MATRIX_SIZE)
	  {
		  for (size_t i = 0; i < sz; i++)
			  pMem[i] = TDynamicVector<T>(sz);
	  }
	  else throw exception("Theoreticaly it is not possible"); //Theoreticaly it is not possible because  MAX_MATRIX_SIZE=(MAX_VECTOR_SIZE)^(1/2)
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  T& at(size_t first, size_t second)
  {
	  if (first >= 0 && first < sz && second >= 0 && second < sz)
		  return pMem[first][second];
	  else throw exception(" (!) [error] (!)\n index out of range");
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
	  return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }
  bool operator!=(const TDynamicMatrix& m) const noexcept
  {
	  return !(*this== m);
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
	  TDynamicMatrix tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] * val;
	  }
	  return tmp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
	  TDynamicVector<T> tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp[i] = pMem[i] * v;
	  }
	  return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
	  TDynamicMatrix tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] + m.pMem[i];
	  }
	  return tmp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
	  TDynamicMatrix tmp(sz);
	  for (size_t i = 0; i < sz; i++)
	  {
		  tmp.pMem[i] = pMem[i] - m.pMem[i];
	  }
	  return tmp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
	  TDynamicMatrix tmp(sz);
	  for (size_t i = 0; i < sz; i++)
		  for (size_t j = 0; j < sz; j++)
			  for (size_t k = 0; k < sz; k++)
				  tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
	  return tmp;

  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
	  for (size_t i = 0; i < v.sz; i++)
		  for (size_t j = 0; j < v.sz; j++)
			  istr >> v.pMem[i][j];
	  return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
	  for (size_t i = 0; i < v.sz; i++)
	  {
		  for (size_t j = 0; j < v.sz; j++)
			  ostr << v.pMem[i][j]<<"   ";
		  ostr << "\n";
	  }
		  
	  return ostr;
  }

  size_t size() const noexcept { return sz; }




  











};

#endif
