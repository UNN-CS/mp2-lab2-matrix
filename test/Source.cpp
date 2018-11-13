#include "utmatrix.h"
//#include <gtest/gtest.h>
#include "gtest.h"


TEST(MyTVectro, false_when_compare_vectors_with_different_size)
{
	TVector<int> v1(1), v2(2);

	ASSERT_FALSE(v1 == v2);
}

TEST(MyTMatrix, can_compare_two_vectors_in_matrices)
{
	TMatrix<int> m1(3), m2(3);

	for (int i = 0; i < 3; i++)
		m1[0][i] = m2[0][i];
	ASSERT_TRUE(m1[0] == m2[0]);
}

TEST(MyTVector, can_add_three_vectors_with_equal_size)
{
	int s = 7;
	TVector<int> v1(s), v2(s), v3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = v2[i] = v3[i] = i;
		expans[i] = 3 * i;
	}
	ans = v1 + v2 + v3;
	EXPECT_EQ(ans, expans);
}

TEST(MyTVector, cant_add_vectors_with_equal_start_index_and_non_equal_size)
{
	int s1 = 7, s2 = 5;
	int st1 = 3, st2 = 3;
	TVector<int> v1(s1, st1), v2(s2, st2);
	EXPECT_ANY_THROW(v1 + v2);
}

TEST(MyTVector, cant_subtract_vectors_with_equal_start_index_and_non_equal_size)
{
	int s1 = 7, s2 = 5;
	int st1 = 3, st2 = 3;
	TVector<int> v1(s1, st1), v2(s2, st2);
	EXPECT_ANY_THROW(v1 - v2);
}

TEST(MyTMatrix, can_add_three_matrix_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = 2 * i * j;
			m3[i][j] = 3 * i * j;
			expans[i][j] = 6 * i * j;
		}
	ans = m1 + m2 + m3;
	EXPECT_EQ(ans, expans);
}

TEST(MyTMatrix, can_subtract_three_matrix_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = 6 * i * j;
			m2[i][j] = 2 * i * j;
			m3[i][j] = 3 * i * j;
			expans[i][j] = i * j;
		}
	ans = m1 - m2 - m3;
	EXPECT_EQ(ans, expans);
}

TEST(MyTMatrix, operator_not_equal_return_false_with_equal_matrix)
{
	int s = 6;
	TMatrix<int>m(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m[i][j] = i * j;
	EXPECT_FALSE(m != m);
}

TEST(MyTMatrix, can_assign_three_matrix)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			expans[i][j] = i * j;

		}
	m3 = m2 = m1;
	EXPECT_EQ(expans, m1);
	EXPECT_EQ(expans, m2);
	EXPECT_EQ(expans, m3);
}

TEST(MyTMatrix, throws_when_set_element_in_lower_triangle)
{
	int s = 2;
	TMatrix<int>m(s);
	ASSERT_ANY_THROW(m[1][0] = 5);
}