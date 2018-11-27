#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(3);
	m[0][0] = 0;
	m[0][1] = 1; 
	m[0][2] = 2;
 	m[1][1] = 3; 
	m[1][2] = 4;
	m[2][2] = 5;
	TMatrix<int> m1(m);

 	EXPECT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(10);
 	TMatrix<int> m1(m);
	m[0] = m[0] + 1;

 	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(10);

 	EXPECT_EQ(10, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(10);
 	m[1][1] = 10;

 	EXPECT_EQ(10, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> m(10);

 	ASSERT_ANY_THROW(m[0][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE+1));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(10);
	TMatrix<int> m1(m);
	m = m;

 	EXPECT_EQ(m, m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(10);
 	TMatrix<int> m1(10);
 	for (int i = 0; i < m.GetSize(); i++)
 		m[i] = i;
 	m1 = m;
			
 	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
 	TMatrix<int> m(10);
 	TMatrix<int> m1(5);
 	m = m1;

 	EXPECT_NE(10, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(10);
 	TMatrix<int> m1(5);
	for (int i = 0; i < m1.GetSize(); i++)
 		m1[i] = m1[i] + 1;
 	m = m1;

	EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(5);
	for (int i = 0; i < m[0].GetSize(); i++)
 		m[i] = m1[i] = i;

  EXPECT_TRUE(m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(10);

 	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(10);
	TMatrix<int> m1(5);

	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	for (int i = 0; i < 2; i++){
 		for (int j = i; j < 2; j++){
			m[i][j] = i + j;
 			m1[i][j] = i + j;
 			m2[i][j] = 2 * i + 2 * j;
 		}
	}

	EXPECT_EQ (m + m1, m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> m1(5);

	ASSERT_ANY_THROW (m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	for (int i = 0; i < 2; i++){
 		for (int j = i; j < 2; j++){
			m[i][j] = i + j + 1;
 			m1[i][j] = i + j;
			m2[i][j] = 1;
		}
	}

	EXPECT_EQ(m2, m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> m1(5);

	ASSERT_ANY_THROW (m - m1);
}

