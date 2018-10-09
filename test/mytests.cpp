#include"utmatrix.h"

#include<gtest/gtest.h>

TEST(TVector, can_created)
{
  ASSERT_NO_THROW(TVector<int> v(13, 14));
}

TEST(TVector, cant_created_with_negative_size)
{
  ASSERT_ANY_THROW(TVector<int> v(-1));
}

TEST(TVector, cant_created_with_negative_start_index)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -1));
}

TEST(TVector, can_get_access)
{
  const int SIZE = 5, STARTINDEX = 2;
  TVector<int> v(SIZE, STARTINDEX);

  ASSERT_NO_THROW(v[STARTINDEX + SIZE - 1] = 0);
}

TEST(TVector, access_operator_check)
{
  const int SIZE = 5, STARTINDEX = 2, VALUE = 1;
  TVector<int> v(SIZE, STARTINDEX);

  v[STARTINDEX + SIZE - 1] = VALUE;

  EXPECT_EQ(VALUE, v[STARTINDEX + SIZE - 1]);
}

TEST(TVector, equal_vectors_compare_returns_true)
{
  const int SIZE = 5, STARTINDEX = 2;
  TVector<int> v2(SIZE, STARTINDEX), v1(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v1[i] = i * 17 - 31;
    v2[i] = v1[i];
  }

  EXPECT_TRUE(v2 == v1);
}

TEST(TVector, not_equal_vectors_compare_returns_false)
{
  const int SIZE = 5, STARTINDEX = 2;
  TVector<int> v1(SIZE, STARTINDEX), v2(SIZE, STARTINDEX);

  v1[SIZE - 1] = 0;
  v2[SIZE - 1] = 1;

  EXPECT_FALSE(v2 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v1(5, 2), v2(6, 2);

  EXPECT_NE(v1, v2);
}

TEST(TVector, copied_vector_equal_to_source_one)
{
  TVector<int> v1(5, 2), v2(v1);

  EXPECT_EQ(v1, v2);
}

TEST(TVector, add_scalar_check)
{
  const int SIZE = 5, STARTINDEX = 2, SCALAR = 3;
  TVector<int> v(SIZE, STARTINDEX), exp(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v[i] = i * 17 - 31;
    exp[i] = v[i] + SCALAR;
  }

  EXPECT_EQ(exp, v + SCALAR);
}

TEST(TVector, substract_scalar_check)
{
  const int SIZE = 5, STARTINDEX = 2, SCALAR = 3;
  TVector<int> v(SIZE, STARTINDEX), exp(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v[i] = i * 17 - 31;
    exp[i] = v[i] - SCALAR;
  }

  EXPECT_EQ(exp, v - SCALAR);
}

TEST(TVector, multiply_scalar_check)
{
  const int SIZE = 5, STARTINDEX = 2, SCALAR = 3;
  TVector<int> v(SIZE, STARTINDEX), exp(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v[i] = i * 17 - 31;
    exp[i] = v[i] * SCALAR;
  }

  EXPECT_EQ(exp, v * SCALAR);
}

TEST(TVector, add_vector_check)
{
  const int SIZE = 5, STARTINDEX = 2;
  TVector<int> v1(SIZE, STARTINDEX), v2(SIZE, STARTINDEX), exp(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v1[i] = i * 17 - 31;
    v2[i] = i * 3 + 53;
    exp[i] = v1[i] + v2[i];
  }

  EXPECT_EQ(exp, v1 + v2);
}

TEST(TVector, substract_vector_check)
{
  const int SIZE = 5, STARTINDEX = 2;
  TVector<int> v1(SIZE, STARTINDEX), v2(SIZE, STARTINDEX), exp(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v1[i] = i * 17 - 31;
    v2[i] = i * 3 + 53;
    exp[i] = v1[i] - v2[i];
  }

  EXPECT_EQ(exp, v1 - v2);
}

TEST(TVector, scalar_multiply)
{
  const int SIZE = 5, STARTINDEX = 2;
  int exp = 0;
  TVector<int> v1(SIZE, STARTINDEX), v2(SIZE, STARTINDEX);

  for (int i = STARTINDEX; i < SIZE + STARTINDEX; ++i)
  {
    v1[i] = i * 17 - 31;
    v2[i] = i * 3 + 53;
    exp += v1[i] * v2[i];
  }

  EXPECT_EQ(exp, v1 * v2);
}

TEST(TMatrix, can_created)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_created_with_negative_size)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-1));
}

TEST(TMatrix, can_get_access)
{
  const int SIZE = 5;
  TMatrix<int> m(SIZE);

  ASSERT_NO_THROW(m[SIZE - 1][SIZE - 1] = 0);
}

TEST(TMatrix, access_operator_check)
{
  const int SIZE = 5, VALUE = 1;
  TMatrix<int> m(SIZE);

  m[SIZE - 1][SIZE - 1] = VALUE;

  EXPECT_EQ(VALUE, m[SIZE - 1][SIZE - 1]);
}

TEST(TMatrix, equal_matrix_compare_returns_true)
{
  const int SIZE = 5;
  TMatrix<int> m1(SIZE), m2(SIZE);

  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = i; j < SIZE; ++j)
    {
      m1[i][j] = j * 3 + i + 7;
      m2[i][j] = m1[i][j];
    }
  }

  ASSERT_TRUE(m2 == m1);
}

TEST(TMatrix, not_equal_matrix_compare_returns_false)
{
  const int SIZE = 5;
  TMatrix<int> m1(SIZE), m2(SIZE);

  m1[0][0] = 0;
  m2[0][0] = 1;

  ASSERT_FALSE(m2 == m1);
}

TEST(TMatrix, copied_matrix_equal_to_source_one)
{
  TMatrix<int> m1(5), m2(m1);

  EXPECT_EQ(m1, m2);
}

TEST(TMatrix, add_matrix_check)
{
  const int SIZE = 5;
  TMatrix<int> m1(SIZE), m2(SIZE), exp(SIZE);

  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = i; j < SIZE; ++j)
    {
      m1[i][j] = i * 10 + j;
      m2[i][j] = i * 1000 + j * 100;
      exp[i][j] = m1[i][j] + m2[i][j];
    }
  }

  EXPECT_EQ(exp, m1 + m2);
}

TEST(TMatrix, substract_matrix_check)
{
  const int SIZE = 5;
  TMatrix<int> m1(SIZE), m2(SIZE), exp(SIZE);

  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = i; j < SIZE; ++j)
    {
      m1[i][j] = i * 10 + j;
      m2[i][j] = i * 1000 + j * 100;
      exp[i][j] = m1[i][j] - m2[i][j];
    }
  }

  EXPECT_EQ(exp, m1 - m2);
}