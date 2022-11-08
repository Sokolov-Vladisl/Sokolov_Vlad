#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	
	TDynamicVector<int> test_v(v);
	
	EXPECT_EQ(v, test_v);
	
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(4);
	v[0] = 5;
	v[1] = 8;
	v[2] = 11;
	v[3] = 14;
	TDynamicVector<int> test_v(v);
	v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0;   // примитивно, но работает

	EXPECT_EQ(5, test_v[0]);
	EXPECT_EQ(8, test_v[1]);
	EXPECT_EQ(11, test_v[2]);
	EXPECT_EQ(14, test_v[3]);
	
  
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(-7) = 78);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(10) = 78);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(v);
	EXPECT_EQ(v, v1);
	ASSERT_NO_THROW(v=v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(10);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = (5 + i * 3) % 17;   //случайный набор чисел
	}
	TDynamicVector<int> v1(10);
	ASSERT_NO_THROW(v1 = v);
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(6);
	v1 = v;
	if (v1.size() == 6)
	{
		ADD_FAILURE();
	}
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(6);
	ASSERT_NO_THROW(v1 = v);
	EXPECT_EQ(v,v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(6);
	v1 = v;
	EXPECT_EQ(v==v1, 1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(10);
	EXPECT_EQ(v == v, 1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(6);
	EXPECT_EQ(v==v1,0);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(4);
	v[0] = 5;
	v[1] = 0;
	v[2] = 15;
	v[3] =10 ;
	ASSERT_NO_THROW(v + 45);
	v = v + 45;
	EXPECT_EQ(v[0], 50);
	EXPECT_EQ(v[1], 45);
	EXPECT_EQ(v[2], 60);
	EXPECT_EQ(v[3], 55);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(4);
	v[0] = 50;
	v[1] = 45;
	v[2] = 60;
	v[3] = 55;
	ASSERT_NO_THROW(v - 45);
	v = v - 45;
	EXPECT_EQ(v[0], 5);
	EXPECT_EQ(v[1], 0);
	EXPECT_EQ(v[2], 15);
	EXPECT_EQ(v[3], 10);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(4);
	v[0] = 1;
	v[1] = 3;
	v[2] = 4;
	v[3] = 2;
	ASSERT_NO_THROW(v * 45);
	v = v * 3;
	EXPECT_EQ(v[0], 3);
	EXPECT_EQ(v[1], 9);
	EXPECT_EQ(v[2], 12);
	EXPECT_EQ(v[3], 6);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> v1(3);
	v[0] = 10; v1[0] = 2;
	v[1] = 3; v1[1] =19 ;
	v[2] = 15; v1[2] = 7;
	ASSERT_NO_THROW(v = v + v1);
	EXPECT_EQ(v[0], 12);
	EXPECT_EQ(v[1], 22);
	EXPECT_EQ(v[2], 22);
	
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> v1(4);
	ASSERT_ANY_THROW(v = v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> v1(3);
	v[0] = 10; v1[0] = 2;
	v[1] = 3; v1[1] = 19;
	v[2] = 15; v1[2] = 7;
	ASSERT_NO_THROW(v = v - v1);
	EXPECT_EQ(v[0], 8);
	EXPECT_EQ(v[1], -16);
	EXPECT_EQ(v[2], 8);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> v1(4);
	ASSERT_ANY_THROW(v = v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> v1(3);
	v[0] = 1; v1[0] = 2;
	v[1] = 3; v1[1] = 1;
	v[2] = 2; v1[2] = 7;
	int summ = 0;
	ASSERT_NO_THROW(summ = v * v1);
	EXPECT_EQ(summ, 19);
	
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> v1(4);
	int summ = 0;
	ASSERT_ANY_THROW(summ = v * v1);
}

