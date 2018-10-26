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
	const int size = 5;
	TMatrix <int> m1(size), m2(size);
	m2 [2][3] = 3;
	m1 = m2;

	EXPECT_EQ (m1[2][3],m2[2][3]);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	const int size = 3;
	TMatrix <int> m1(size), m2(size);
	m2=m1;
	m1[1][2] = 7;

	EXPECT_EQ (0,m2[1][2]);
}

TEST(TMatrix, can_get_size)
{
	const int size = 3;
	TMatrix <int> m(size);

	EXPECT_EQ (size,m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	const int size = 5;
	TMatrix <int> m(size);
	m[3][4] = 8;

	EXPECT_EQ(8, m[3][4]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	const int size = 5;
	TMatrix <int> m(size);

	ASSERT_ANY_THROW(m[3][-1] = 8);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	const int size = 5;
	TMatrix <int> m(size);

	ASSERT_ANY_THROW(m[3][5] = 8);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	const int size = 5;
	TMatrix <int> m(size);

	ASSERT_NO_THROW(m=m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 5;
	TMatrix <int> m1(size), m2(size);

	ASSERT_NO_THROW(m1=m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 5, size2 = 3;
	TMatrix <int> m1(size1), m2(size2);
	m2 = m1;

	EXPECT_EQ (size1, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 5, size2 = 3;
	TMatrix <int> m1(size1), m2(size2);

	ASSERT_NO_THROW(m1=m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int size = 3;
	TMatrix <int> m1(size), m2(size);
	m1[1][2] = 5;
	m2[1][2] = 5;

	ASSERT_EQ (m1, m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	const int size = 3;
	TMatrix <int> m(size);

	ASSERT_EQ (m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 5, size2 = 3;
	TMatrix <int> m1(size1), m2(size2);

	EXPECT_NE (m1, m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int size = 3;
	TMatrix <int> m1(size), m2(size);
	int i, j;
	for (i = 0; i < 3; i++)
    for (j = i; j < 3; j++ )
    {
      m1[i][j] =  1;
      m2[i][j] = 10;
    }
	TMatrix <int> m3 = m1 + m2;

	EXPECT_EQ(11 , m3[0][0]);
	EXPECT_EQ(11 , m3[1][1]);
	EXPECT_EQ(11 , m3[2][2]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size1 = 3, size2 = 5;
	TMatrix <int> m1(size1), m2(size2);

	ASSERT_ANY_THROW (m1+m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 3;
	TMatrix <int> m1(size), m2(size);
	int i, j;
	for (i = 0; i < 3; i++)
    for (j = i; j < 3; j++ )
    {
      m1[i][j] =  10;
      m2[i][j] = 1;
    }
	TMatrix <int> m3 = m1 - m2;

	EXPECT_EQ(9 , m3[0][0]);
	EXPECT_EQ(9 , m3[1][1]);
	EXPECT_EQ(9 , m3[2][2]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size1 = 3, size2 = 5;
	TMatrix <int> m1(size1), m2(size2);

	ASSERT_ANY_THROW (m1-m2);
}

