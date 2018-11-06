#include "utmatrix.h"

#include "gtest.h"

TEST(TVector_MY_TEST, can_add_three_vectors_with_equal_size)
{
	TVector<int> v1(2);
	TVector<int> v2(2);
	TVector<int> v3(2);

	TVector<int> v(2);
	TVector<int> v_test(2);

	v1[0] = 1;
	v1[1] = 1;

	v2[0] = 2;
	v2[1] = 2;

	v3[0] = 3;
	v3[1] = 3;

	for (int i = 0; i < 2; i++)
	{
		v[i] = v1[i] + v2[i] + v3[i];
	}

	v_test = v1 + v2 + v3;

	EXPECT_EQ(true, v == v_test);
}

TEST(TVector_MY_TEST, can_subtract_three_vectors_with_equal_size)
{
	TVector<int> v1(2);
	TVector<int> v2(2);
	TVector<int> v3(2);

	TVector<int> v(2);
	TVector<int> v_test(2);

	v1[0] = 1;
	v1[1] = 1;

	v2[0] = 2;
	v2[1] = 2;

	v3[0] = 3;
	v3[1] = 3;

	for (int i = 0; i < 2; i++)
	{
		v[i] = v1[i] - v2[i] - v3[i];
	}

	v_test = v1 - v2 - v3;

	EXPECT_EQ(true, v == v_test);
}

TEST(TVector_MY_TEST, cant_get_value_less_than_start_index)
{
	TVector<int> v(2, 1);

	ASSERT_ANY_THROW(v[0]);
}

TEST(TVector_MY_TEST, vectors_with_different_start_index_are_not_equal)
{
	TVector<int> v1(3, 1);
	TVector<int> v2(3, 2);

	EXPECT_EQ(false, v1 == v2);
}

TEST(TVector_MY_TEST, cant_add_vectors_with_not_equal_start_index)
{
	TVector<int> v1(3, 1);
	TVector<int> v2(3, 2);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector_MY_TEST, cant_subtract_vectors_with_not_equal_start_index)
{
	TVector<int> v1(3, 1);
	TVector<int> v2(3, 2);

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector_MY_TEST, cant_multiply_vectors_with_not_equal_start_index)
{
	TVector<int> v1(3, 1);
	TVector<int> v2(3, 2);

	ASSERT_ANY_THROW(v1 * v2);
}



TEST(TMatrix_MY_TEST, can_add_three_matrix_with_equal_size)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	TMatrix<int> m3(2);

	m1[0][0] = 1; m1[0][1] = 1; m1[1][1] = 1;
	m2[0][0] = 2; m2[0][1] = 2; m2[1][1] = 2;
	m3[0][0] = 3; m3[0][1] = 3; m3[1][1] = 3;

	TMatrix<int> m(2);
	TMatrix<int> m_test(2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = i; j < 2; j++)
		{
			m[i][j] = m1[i][j] + m2[i][j] + m3[i][j];
		}
	}

	m_test = m1 + m2 + m3;

	EXPECT_EQ(true, m == m_test);
}

TEST(TMatrix_MY_TEST, can_subtract_three_matrix_with_equal_size)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	TMatrix<int> m3(2);

	m1[0][0] = 1; m1[0][1] = 1; m1[1][1] = 1;
	m2[0][0] = 2; m2[0][1] = 2; m2[1][1] = 2;
	m3[0][0] = 3; m3[0][1] = 3; m3[1][1] = 3;

	TMatrix<int> m(2);
	TMatrix<int> m_test(2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = i; j < 2; j++)
		{
			m[i][j] = m1[i][j] - m2[i][j] - m3[i][j];
		}
	}

	m_test = m1 - m2 - m3;

	EXPECT_EQ(true, m == m_test);
}

TEST(TMatrix_MY_TEST, cant_get_value_less_than_main_diagonal)
{
	TMatrix<int> m(2);

	ASSERT_ANY_THROW(m[1][0]);
}

TEST(TMatrix_MY_TEST, compare_different_matrices_return_false)
{
	TMatrix<int> m1(1);
	TMatrix<int> m2(1);

	m1[0][0] = 1;
	m2[0][0] = 2;

	EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix_MY_TEST, can_assign_three_matrices)
{
	TMatrix<int> m1(1);
	TMatrix<int> m2(2);
	TMatrix<int> m3(3);

	m1[0][0] = 1;
	m2[0][0] = 2; m2[0][1] = 2; m2[1][1] = 2;
	m3[0][0] = 3; m3[0][1] = 3; m3[0][2] = 3; m3[1][1] = 3; m3[1][2] = 3; m3[2][2] = 3;

	m1 = m2 = m3;

	EXPECT_EQ(true, m1 == m2);
	EXPECT_EQ(true, m1 == m3);
}