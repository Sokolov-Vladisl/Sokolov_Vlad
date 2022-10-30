#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 14;
	m[1][0] = 12;
	m[1][1] = 8;
	TDynamicMatrix<int> m1(m);
	m[0][0] = 0;
	m[0][1] = 0;
	m[1][0] = 0;
	m[1][1] = 0;
	EXPECT_EQ(m1[0][0], 1);
	EXPECT_EQ(m1[0][1], 14);
	EXPECT_EQ(m1[1][0], 12);
	EXPECT_EQ(m1[1][1], 8);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(13);
	EXPECT_EQ(m.size(), 13);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(10);
	ASSERT_NO_THROW(m[5][8] = 13); 
	EXPECT_EQ(m[5][8], 13);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(10);
	ASSERT_ANY_THROW(m[-5][8] = 13);
	ASSERT_ANY_THROW(m[5][-8] = 13);
	ASSERT_ANY_THROW(m[-5][-8] = 13);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(10);
	ASSERT_ANY_THROW(m[15][8] = 13);
	ASSERT_ANY_THROW(m[5][18] = 13);
	ASSERT_ANY_THROW(m[15][18] = 13);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(10);
	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(10);
	m1 = m2;
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(5);
	ASSERT_NO_THROW(m2 = m1);
	if (m2.size() == 5)
	{
		ADD_FAILURE();
	}
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(5);
	ASSERT_NO_THROW(m1 = m2);
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	m1[0][0] = 2;
	m1[0][1] = 3;
	m1[1][0] = 1;
	m1[1][1] = 8;
	m2[0][0] = 2;
	m2[0][1] = 3;
	m2[1][0] = 1;
	m2[1][1] = 8;
	ASSERT_NO_THROW(m1 == m2);
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(7);
	ASSERT_NO_THROW(m == m);
	if (m != m)
	{
		ADD_FAILURE();
	}
	EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(7);
	TDynamicMatrix<int> m2(13);
	ASSERT_NO_THROW(m1 == m2);
	if (m1 == m2)
	{
		ADD_FAILURE();
	}
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(7);
	TDynamicMatrix<int> m2(7);
	m1[0][0] = 12; m2[0][0] = 51;
	m1[2][5] = 41; m2[2][5] = 2;
	m1[3][2] = 42; m2[3][2] = 4;
	ASSERT_NO_THROW(m1 + m2);
	m1 = m2 + m1;
	EXPECT_EQ(m1[0][0], 63);
	EXPECT_EQ(m1[2][5], 43);
	EXPECT_EQ(m1[3][2], 46);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(7);
	TDynamicMatrix<int> m2(3);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(7);
	TDynamicMatrix<int> m2(7);
	m1[0][0] = 12; m2[0][0] = 51;
	m1[2][5] = 41; m2[2][5] = 2;
	m1[3][2] = 42; m2[3][2] = 3;
	ASSERT_NO_THROW(m1 - m2);
	m1 = m1 - m2;
	EXPECT_EQ(m1[0][0], -39);
	EXPECT_EQ(m1[2][5], 39);
	EXPECT_EQ(m1[3][2], 39);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(7);
	TDynamicMatrix<int> m2(3);
	ASSERT_ANY_THROW(m1 - m2);
}

