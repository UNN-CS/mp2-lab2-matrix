#include "utmatrix.h"

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
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	ASSERT_EQ(v, v1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	ASSERT_NE(&v, &v1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][3] = 4;

	EXPECT_EQ(4, v[0][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[-1][3] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[4][3] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	ASSERT_EQ(&v, &(v = v));
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(4), v1(4);
	v1 = v;
	ASSERT_EQ(v, v1);
	ASSERT_NO_THROW(v = v1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v(4), v1(10);
	v1 = v;
	ASSERT_EQ(v.GetSize(), v1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(4), v1(10);
	ASSERT_NO_THROW(v = v1);
	v1 = v;
	ASSERT_EQ(v, v1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v(4), v1(v);

	ASSERT_TRUE(v == v1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(4);

	ASSERT_TRUE(v == v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(4), v1(10);
	ASSERT_NE(v, v1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(4), v1(4), v2(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		for (int j = i; j < v.GetSize(); j++)
		{
			v[i][j] = i;
			v1[i][j] = j;
			v2[i][j] = i + j;
		}
	}
	ASSERT_NO_THROW(v1 + v2);
	ASSERT_EQ(v + v1, v2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(4), v1(10);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(4), v1(4), v2(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		for (int j = i; j < v.GetSize(); j++)
		{
			v[i][j] = i;
			v1[i][j] = j;
			v2[i][j] = i - j;
		}
	}
	ASSERT_NO_THROW(v1 - v2);
	ASSERT_EQ(v - v1, v2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(4), v1(10);
	ASSERT_ANY_THROW(v - v1);
}
//мои тесты
TEST(TMatrix, can_add_three_matrices_with_equal_size)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(size), m3(size), exp_res(size);
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; j++)
		{
		m1[i][j] = i + j;
		m2[i][j] = i * j;
		m3[i][j] = i % (j + 1);
		exp_res[i][j] = i + j + i * j + i % (j + 1);
		}

	EXPECT_EQ(m1 + m2 + m3, exp_res);
}
TEST(TMatrix, can_create_matrix_from_vector)
{
	TVector<TVector<int>> v(5);

	ASSERT_NO_THROW(TMatrix<int> m(v));
}
TEST(TMatrix, can_apply_few_assignment_operators)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(size), m3(size);
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j)
			m1[i][j] = i + j;
	m3 = m2 = m1;

	EXPECT_TRUE(m2 == m1);
	EXPECT_TRUE(m3 == m1);
}
TEST(TMatrix, not_equal_to_operator_returns_false_being_applied_to_equal_matrices)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(size);
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j)
		{
		m1[i][j] = i + j;
		m2[i][j] = i + j;
		}

	EXPECT_FALSE(m1 != m2);
}
TEST(TMatrix, not_equal_to_operator_returns_true_being_applied_to_not_equal_matrices)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(size);
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j)
		{
		m1[i][j] = i + j;
		m2[i][j] = i + j + 10;
		}

	EXPECT_TRUE(m1 != m2);
}
