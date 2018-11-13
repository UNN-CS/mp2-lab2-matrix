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
	const int size = 2;
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = 1;
	TMatrix<int> mt(m);

	EXPECT_EQ(m, mt);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	const int size = 3;
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = 1;
	TMatrix<int>  mt(m);
	TMatrix<int>* p = &m;
	TMatrix<int>* pt = &mt;

	EXPECT_NE(p, pt);
}

TEST(TMatrix, can_get_size)
{
	const int size = 6;
	TMatrix<int> m(size);

	EXPECT_EQ(size, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	const int size = 3;
	const int val = 4;
	TMatrix<int> m(size);
	m[1][2] = val;

	EXPECT_EQ(val, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	const int size = 3;
	const int val = 4;
	TMatrix<int> m(size);

	EXPECT_ANY_THROW(m[-1][2] = val);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	const int size = 3;
	const int val = 4;
	TMatrix<int> m(size);

	EXPECT_ANY_THROW(m[-1][2] = val);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	const int size = 3;
	TMatrix<int> m(size), mt(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			m[i][j] = 1;
			mt[i][j] = 1;
		}
	
	EXPECT_EQ(mt, m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 3;
	TMatrix<int> m(size), mt(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			mt[i][j] = 1;
	m = mt;

	EXPECT_EQ(mt, m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size = 3, sizet = 4;
	TMatrix<int> m(size), mt(sizet);
	for (int i = 0; i < sizet; i++)
		for (int j = i; j < sizet; j++)
			mt[i][j] = 1;
	m = mt;

	EXPECT_EQ(sizet, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size = 3, sizet = 4;
	TMatrix<int> m(size);
	for (int i = 0;i < size;++i)
		for (int j = i;j < size;++j)
			m[i][j] = 1;
	TMatrix<int> mt(sizet);
	mt = m;

	EXPECT_EQ(mt, m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int size = 4;
	TMatrix<int> m(size), mt(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			m[i][j] = 1;
			mt[i][j] = 1;
		}
	
	EXPECT_TRUE(m == mt);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	const int size = 3;
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = 1;
	
	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size = 3, sizet = 4;
	TMatrix<int> m(size), mt(sizet);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = 1;
	for (int i = 0; i < sizet; i++)
		for (int j = i; j < sizet; j++)
			mt[i][j] = 1;

	EXPECT_FALSE(m == mt);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(size), mt(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			m1[i][j] = 6;
			m2[i][j] = 7;
			mt[i][j] = 13;
		}

	EXPECT_EQ(mt, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(2), mt(3);

	EXPECT_ANY_THROW(m + mt);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(size), mt(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			m1[i][j] = 8;
			m2[i][j] = 5;
			mt[i][j] = 3;
		}

	EXPECT_EQ(mt, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(2), mt(3);

	EXPECT_ANY_THROW(m - mt);
}

