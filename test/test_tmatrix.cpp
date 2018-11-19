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
  TMatrix<int> m(3);
  m[1][1] = 5;
  TMatrix<int> m1(m);
  EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m(3);
  m[1][1] = 5;
  TMatrix<int> m1(m);
  EXPECT_EQ(m[1][1], m1[1][1]);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> m(10);
  EXPECT_EQ(10, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(10);
  m[1][1] = 3;
  EXPECT_EQ(3, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-1));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(2);
  ASSERT_ANY_THROW(m[4]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> m(4);
  m[1][1] = 5;
  m = m;
  EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> m(4);
  TMatrix<int> m1(4);
  m[1][1] = 5;
  m1 = m;
  EXPECT_EQ(m1, m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> m(5);
  TMatrix<int> m1(3);
  m1 = m;
  EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> m(6);
  TMatrix<int> m1(45);
  m1 = m;
  EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> m(6);
  TMatrix<int> m1(6);
  m[1][1] = 5;
  m1 = m;
  EXPECT_EQ(1, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> m(6);
  m[1][1] = 5;
  EXPECT_EQ(1, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m(3);
  TMatrix<int> m1(5);
  EXPECT_EQ(1, m != m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> m1(3);
  TMatrix<int> m2(3);
  m[1][1] = 3;
  m1[1][1] = 3;
  m2[1][1] = 6;
  EXPECT_EQ(m2, m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> m1(4);
  EXPECT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> m1(3);
  TMatrix<int> m2(3);
  m[1][1] = 6;
  m1[1][1] = 2;
  m2[1][1] = 4;
  EXPECT_EQ(m2, m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> m(3);
  TMatrix<int> m1(4);
  EXPECT_ANY_THROW(m - m1);
}

