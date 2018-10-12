#include "utmatrix.h"
#include <gtest/gtest.h>

TEST(my_test, can_get_and_compare_elements_from_main_diagonal)
{
	const int size = 10000;
	TMatrix<int> m(size);
	for (int i = 0; i < size; ++i)
		m[i][i] = i;
	ASSERT_EQ(m[size-2][size-2] + 1, m[size-1][size-1]);
}

TEST(my_test, can_init_matrix_with_size_1_and_work_with_elements)
{
	TMatrix<int> m(1);
	m[0][0] = 9;
	ASSERT_EQ(9, m[0][0]);
}

TEST(my_test, can_add_matrixes_multiple_times)
{
	TMatrix<int>a(10), b(10), c(10);
	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
			a[i][j] = b[i][j] = c[i][j] = i + j;
	auto d = a + b + c;
	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
			EXPECT_EQ(d[i][j], 3 * (i + j));
}

TEST(my_test, can_substract_matrixes_multiple_times)
{
	TMatrix<int>a(10), b(10), c(10);
	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
			a[i][j] = b[i][j] = c[i][j] = -(i + j);
	auto d = a + b + c;
	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
			EXPECT_EQ(d[i][j], -3 * (i + j));
}

TEST(my_test, can_assing_matrixes_multiple_times)
{
	TMatrix<int>a(10), b(10), c(10);
	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
			a[i][j] = b[i][j] = c[i][j] = i + j;
	auto d = a = b = c;
	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
			EXPECT_EQ(d[i][j], i + j);
}

TEST(my_test, cant_assign_undefined_element)
{
	TMatrix<int> a(2);
	ASSERT_ANY_THROW(a[1][0] = 10);
}

TEST(my_test, can_define_that_matrixes_are_not_equal)
{
	TMatrix<int> a(10), b(10);
	a[0][0] = 1;
	ASSERT_NE(a, b);
}

TEST(my_test, cant_read_undefined_elements)
{
	TMatrix<int> a(10);
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (j < i)
				EXPECT_ANY_THROW(a[i][j]);
}

TEST(my_test, vectors_with_different_start_indexes_are_not_equal)
{
	TVector<int> a(5, 0), b(5, 5);
	ASSERT_NE(a, b);
}

TEST(my_test, )
{
	TVector<int> a(5);
	for (int i = 0; i < 5; ++i)
		a[i] = i;
	ASSERT_EQ(30, a * a);
}