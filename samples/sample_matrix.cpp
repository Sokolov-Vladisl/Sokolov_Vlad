// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"

//---------------------------------------------------------------------------




double rand_between(const double min, const double max) {
	if (max == min)
		return max;
	if (max < min)
		return rand_between(max, min);
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}









void main()
{
  
	int choice,N;

  setlocale(LC_ALL, "Russian");

  cout << endl << endl << endl;
  cout << "   [ Внимание ! ]                                 " << endl;
  cout << "       В данной программе {sample} матрицы        " << endl;
  cout << "       имеют  тип  данных  double, а также        " << endl;
  cout << "       являются квадратными (для корректности)    " << endl << endl << endl;
  cout << "   Рекомендуется перейти в полноэкранный режим    " << endl;
  cout << endl << endl << endl;
  system("pause");
  system("cls");

  cout <<endl<< " Важный выбор"<<endl<<endl<<endl;
  cout << " 1) Сгенерировать матрицы случайно" << endl;
  cout << " 2) Создать матрицы вручную" << endl<<endl;
  cin >> choice;

  system("cls");
  bool work = true;


  cout << "Введите размер матриц  [ N x N ]" << endl << endl << "  N = ";
  cin >> N;
  double A, B;
  TDynamicMatrix<double> a(N), b(N);

  if(choice==1)
  {
  

	  

		  double A, B;
	
		  cout << "А теперь выберите диапазон значений   [ от (A) до (B) ]" << endl << endl << "  A = ";
		  cin >> A;
		  cout << "  B =";
		  cin >> B;

		  cout <<endl<< "    матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  a.at(i, j) = rand_between(A,B);
				  b.at(i, j) = rand_between(A, B);						
				  cout << "  "<<a.at(i, j)<<"  ";
			  }
			  cout << endl<<endl<<endl;
		  }
		  cout << endl<<endl<<endl<<endl<<endl<<endl<<endl << "    матрица b :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << b.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
  }
  if (choice == 2)
  {

	  cout << endl << "   Первая матрица :" << endl << endl;
	  for (int i = 0; i < N; i++)
	  {
		  cout << i + 1 << "-ая СТРОКА:  "<<endl;
		  for (int j = 0; j < N; j++)
		  {
			  cin>> a.at(i, j);
		  }
		  cout << endl << endl << endl;
	  }
	  cout << endl << endl << endl << endl << endl << endl << endl << "   Вторая матрица :" << endl << endl;
	  for (int i = 0; i < N; i++)
	  {
		  cout << i + 1 << "-ая СТРОКА:  "<<endl;
		  for (int j = 0; j < N; j++)
		  {
			  cin >> b.at(i, j);
		  }
		  cout << endl << endl << endl;
	  }

	  system("cls");

	  cout << endl << "    матрица a :" << endl << endl;
	  for (int i = 0; i < N; i++)
	  {
		  cout << i + 1 << "-ая СТРОКА:  ";
		  for (int j = 0; j < N; j++)
		  {
			  cout << "  " << a.at(i, j) << "  ";
		  }
		  cout << endl << endl << endl;
	  }

	  cout << endl << endl << endl << endl << endl << endl << endl << "    матрица b :" << endl << endl;
	  for (int i = 0; i < N; i++)
	  {
		  cout << i + 1 << "-ая СТРОКА:  ";
		  for (int j = 0; j < N; j++)
		  {
			  cout << "  " << b.at(i, j) << "  ";
		  }
		  cout << endl << endl << endl;
	  }
  }
  if(choice!=1 && choice!=2)
  {
	  work = false;
  }



  double val;

  while (work)
  {
	  cout << endl << endl << "Выберите операцию :" << endl << endl;

	  cout << " 1) a=a*b  " << endl;
	  cout << " 2) a=b*a  " << endl;
	  cout << " 3) a=a+b  " << endl;
	  cout << " 4) a=a-b  " << endl;
	  cout << " 5) a=a*a  " << endl;
	  cout << " 6) b=b*b  " << endl;
	  cout << " 7) ULTIMATE  " << endl<<endl;       // a=(a+b)*b-a ;
	  cout << " 8) Посмотреть матрицы a и b" << endl<<endl<<endl<<endl;
	  cout << " 0) Завершить программу" << endl << endl << "Мой выбор : ";
	  cin >> choice;
	  system("cls");


	  if (choice == 1)
	  {
		  cout <<endl<< " 1) a=a*b   " << endl<<endl;
		  a=a*b;

		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 2)
	  {
		  cout << endl << " 1) a=b*a   " << endl << endl;
		  a = b * a;

		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 3)
	  {
		  cout << endl << " 1) a=a+b   " << endl << endl;
		  a = a+b;

		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 4)
	  {
		  cout << endl << " 1) a=a-b   " << endl << endl;
		  a = a - b;

		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 5)
	  {
		  cout << endl << " 1) a=a*a   " << endl << endl;
		  a = a * a;

		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 6)
	  {
		  cout << endl << " 1) b=b*b   " << endl << endl;
		  b = b * b;

		  cout << endl << "   матрица b :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << b.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 7)
	  {
		  cout << endl << "a = (a + b) * b - a" << endl << endl;
		  a = (a + b) * b - a;

		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 8)
	  {
		  
		  cout << endl << "   матрица a :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << a.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  cout << endl << "   матрица b :" << endl << endl;
		  for (int i = 0; i < N; i++)
		  {
			  cout << i + 1 << "-ая СТРОКА:  ";
			  for (int j = 0; j < N; j++)
			  {
				  cout << "  " << b.at(i, j) << "  ";
			  }
			  cout << endl << endl << endl;
		  }
		  system("pause");
		  system("cls");
	  }
	  if (choice == 0)
	  {
		  work = false;
	  }

  }




 
}
//---------------------------------------------------------------------------
