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
    TMatrix<int> m1(5);
    m1[0][0] = 5; m1[0][1] = 7; m1[0][2] = 8; m1[0][3] = 3; m1[0][4] = 4;
    m1[1][1] = 5; m1[1][2] = 7; m1[1][3] = 8; m1[1][4] = 3;
    m1[2][2] = 5; m1[2][3] = 7; m1[2][4] = 8;
    m1[3][3] = 5; m1[3][4] = 7;
    m1[4][4] = 5;
    TMatrix<int> m2(m1);
    ASSERT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(m1);
    ASSERT_NE(&m1, &m2);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(5);
    ASSERT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    ASSERT_NO_THROW(m[3][3] = 7);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[-5][-5]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[6][6]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m1(5), m2(5);
    m2[3][3] = 7;
    ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m1(5), m2(6);
	m1 = m2;
    ASSERT_EQ(m1.GetSize(), 6);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m1(5), m2(6);
    ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m1(5), m2(5);
    ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(5);
    ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m1(5), m2(6);
    ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m1(5), m2(5);
    ASSERT_NO_THROW(m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m1(5), m2(6);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(5), m2(5);
    ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m1(5), m2(6);
    ASSERT_ANY_THROW(m1 - m2);
}

/*-----------------------------------MY TESTS(4)-----------------------------------*/

TEST(TMatrix, addition_matrixes_works_right)
{
    TMatrix<int> m1(5), m2(5), m3(5);

    m1[0][0] = 5; m1[0][1] = 7; m1[0][2] = 8; m1[0][3] = 3; m1[0][4] = 4;
    m1[1][1] = 5; m1[1][2] = 7; m1[1][3] = 8; m1[1][4] = 3;
    m1[2][2] = 5; m1[2][3] = 7; m1[2][4] = 8;
    m1[3][3] = 5; m1[3][4] = 7;
    m1[4][4] = 5;

    m2[0][0] = 5; m2[0][1] = 7; m2[0][2] = 8; m2[0][3] = 3; m2[0][4] = 4;
    m2[1][1] = 5; m2[1][2] = 7; m2[1][3] = 8; m2[1][4] = 3;
    m2[2][2] = 5; m2[2][3] = 7; m2[2][4] = 8;
    m2[3][3] = 5; m2[3][4] = 7;
    m2[4][4] = 5;

    m3[0][0] = 10; m3[0][1] = 14; m3[0][2] = 16; m3[0][3] = 6; m3[0][4] = 8;
    m3[1][1] = 10; m3[1][2] = 14; m3[1][3] = 16; m3[1][4] = 6;
    m3[2][2] = 10; m3[2][3] = 14; m3[2][4] = 16;
    m3[3][3] = 10; m3[3][4] = 14;
    m3[4][4] = 10;

    ASSERT_EQ(m1 + m2, m3);
}

TEST(TMatrix, subtraction_vectors_works_right)
{
    TMatrix<int> m1(5), m2(5), m3(5);

    m1[0][0] = 5; m1[0][1] = 7; m1[0][2] = 8; m1[0][3] = 3; m1[0][4] = 4;
    m1[1][1] = 5; m1[1][2] = 7; m1[1][3] = 8; m1[1][4] = 3;
    m1[2][2] = 5; m1[2][3] = 7; m1[2][4] = 8;
    m1[3][3] = 5; m1[3][4] = 7;
    m1[4][4] = 5;

    m2[0][0] = 5; m2[0][1] = 7; m2[0][2] = 8; m2[0][3] = 3; m2[0][4] = 4;
    m2[1][1] = 5; m2[1][2] = 7; m2[1][3] = 8; m2[1][4] = 3;
    m2[2][2] = 5; m2[2][3] = 7; m2[2][4] = 8;
    m2[3][3] = 5; m2[3][4] = 7;
    m2[4][4] = 5;

    m3[0][0] = 0; m3[0][1] = 0; m3[0][2] = 0; m3[0][3] = 0; m3[0][4] = 0;
    m3[1][1] = 0; m3[1][2] = 0; m3[1][3] = 0; m3[1][4] = 0;
    m3[2][2] = 0; m3[2][3] = 0; m3[2][4] = 0;
    m3[3][3] = 0; m3[3][4] = 0;
    m3[4][4] = 0;

    ASSERT_EQ(m1 - m2, m3);
}

TEST(TMatrix, compare_matrix_with_itself_with_inequality_sign_return_false)
{
    TMatrix<int> m(5);

    ASSERT_FALSE(m != m);
}

TEST(TMatrix, compare_matrices_with_different_size_with_inequality_sign_return_true)
{
    TMatrix<int> m1(5), m2(6);

    ASSERT_TRUE(m1 != m2);
}
