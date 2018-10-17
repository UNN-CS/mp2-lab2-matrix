#include "../include/utmatrix.h"

#include <gtest/gtest.h>
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
	TMatrix<int> source(5);
	source[0][0] = 12;
	TMatrix<int> copiedM(source);
	EXPECT_EQ(copiedM, source);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> source(5);
	TMatrix<int> copiedM(source);
	EXPECT_NE(&source, &copiedM);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(10);
	EXPECT_EQ(10, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(10);
	m[0][0] = 33;
	EXPECT_EQ(33, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-4));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(10);
	m[0] = 321;
	m = m;
	EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(4);
	m[0][0] = 32;
	m2 = m;
	EXPECT_EQ(m2, m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(4), m2(7);
	m1[0][2] = 10;
	m2 = m1;
	EXPECT_EQ(4, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(7);
	m[0][0] = 32;
	m2 = m;
	EXPECT_EQ(m2, m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(4);
	m[0][0] = 32;
	m2 = m;
	EXPECT_EQ(1, m2 == m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(4);
	m[0][0] = 32;
	EXPECT_EQ(1, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(7);
	m[0][0] = 32;
	m2[0][0] = 32;
	EXPECT_EQ(1, m2 != m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(4);
	TMatrix<int> m3(4);
	m[0][0] = 32;
	m2[0][0] = 32;
	m3[0][0] = 64;
	EXPECT_EQ(m3, m + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(7);
	m[0][0] = 32;
	m2[0][0] = 32;
	EXPECT_ANY_THROW(m2 + m);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(4);
	TMatrix<int> m3(4);
	m[0][0] = 128;
	m2[0][0] = 64;
	m3[0][0] = 64;
	EXPECT_EQ(m3, m - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m2(7);
	m[0][0] = 32;
	m2[0][0] = 44;
	EXPECT_ANY_THROW(m2 - m);
}

