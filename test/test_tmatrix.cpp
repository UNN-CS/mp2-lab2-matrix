#include "utmatrix.h"

#include "gtest.h"

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
	int val = 5;
	TMatrix<int> m1(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
		}
	}
	TMatrix<int> m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	int val = 10;
	TMatrix<int> m1(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
		}
	}
	TMatrix<int> m2(val);
	m2[0][0] = val;

	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);

	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[0][0] = 5;

	EXPECT_EQ(5, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[0][-1] = -1);
	ASSERT_ANY_THROW(m[-1][0] = -1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	int val = 5;
	TMatrix<int> m(val);

	ASSERT_ANY_THROW(m[0][val] = val);
	ASSERT_ANY_THROW(m[val][0] = val);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	int val = 5;
	TMatrix<int> m(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m[i][j] = i + 1;
		}
	}

	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
		}
	}
	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(2 * val);
	for (int i = 0; i < (2 * val); ++i)
	{
		for (int j = i; j < (2 * val); ++j)
		{
			m2[i][j] = i + 1;
		}
	}
	m1 = m2;

	EXPECT_EQ(m2.GetSize(), m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(2 * val);
	for (int i = 0; i < (2 * val); ++i)
	{
		for (int j = i; j < (2 * val); ++j)
		{
			m2[i][j] = i + 1;
		}
	}

	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 1;
		}
	}

	EXPECT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	int val = 5;
	TMatrix<int> m(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m[i][j] = i + 1;
		}
	}

	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(2 * val);
	for (int i = 0; i < (2 * val); ++i)
	{
		for (int j = i; j < (2 * val); ++j)
		{
			m2[i][j] = i + 1;
		}
	}
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
		}
	}

	EXPECT_TRUE(m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
		}
	}

	ASSERT_NO_THROW(m1 = m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(2 * val);
	for (int i = 0; i < (2 * val); ++i)
	{
		for (int j = i; j < (2 * val); ++j)
		{
			m2[i][j] = i + 2;
		}
	}
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
		}
	}

	ASSERT_ANY_THROW(m1 = m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
		}
	}

	ASSERT_NO_THROW(m1 = m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(2 * val);
	for (int i = 0; i < (2 * val); ++i)
	{
		for (int j = i; j < (2 * val); ++j)
		{
			m2[i][j] = i + 2;
		}
	}
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
		}
	}

	ASSERT_ANY_THROW(m1 = m1 - m2);
}

// my tests:

TEST(TMatrix, can_add_three_matrices_with_equal_size_MY_TEST)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	TMatrix<int> m3(val);
	TMatrix<int> m(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
			m3[i][j] = i + 3;
			m[i][j] = 3 * i + 6;
		}
	}
	m1 = m1 + m2 + m3;

	EXPECT_EQ(m1, m);
}

TEST(TMatrix, can_subtract_three_matrices_with_equal_size_MY_TEST)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	TMatrix<int> m3(val);
	TMatrix<int> m(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
			m3[i][j] = i + 3;
			m[i][j] = -i - 4;
		}
	}
	m1 = m1 - m2 - m3;

	EXPECT_EQ(m1, m);
}

TEST(TMatrix, can_assign_three_matrices_of_equal_size_MY_TEST)
{
	int val = 5;
	TMatrix<int> m1(val);
	TMatrix<int> m2(val);
	TMatrix<int> m3(val);
	for (int i = 0; i < val; ++i)
	{
		for (int j = i; j < val; ++j)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
			m3[i][j] = i + 3;
		}
	}
	m1 = m2 = m3;

	EXPECT_EQ(m1, m2);
	EXPECT_EQ(m2, m3);
}

TEST(TMatrix, can_create_zero_matrix_MY_TEST)
{
	ASSERT_NO_THROW(TMatrix<int> m(0));
}

TEST(TMatrix, cant_set_and_get_lower_matrix_elements_MY_TEST)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[1][0] = 10);
	ASSERT_ANY_THROW(m[2][0] = 10);
	ASSERT_ANY_THROW(m[2][1] = 10);
	ASSERT_ANY_THROW(int elem = m[1][0]);
}