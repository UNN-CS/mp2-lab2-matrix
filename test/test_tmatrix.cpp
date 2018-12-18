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
	TMatrix<int> m(5);
	TMatrix<int> a(m);
	EXPECT_EQ(m,a);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> a(m);
	EXPECT_NE(&m, &a);
}

TEST(TMatrix, can_get_size)
{
	int z = 5;
	ASSERT_NO_THROW(TMatrix<int> m(z));
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> M(4);
	M[1][1] = 4;

  EXPECT_EQ(4,M[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][-1]=4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[5][3] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	m[0][1] = 2;
	m[3][3] = 4;

	ASSERT_NO_THROW(m=m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> a(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 4;
	a = m;

	EXPECT_EQ( 1, a==m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(7);
	a = m;
	EXPECT_EQ(5, a.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{

	TMatrix<int> m(5);
	TMatrix<int> a(7);

//	a = m;
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 4;
	a = m;
	EXPECT_EQ(1, a == m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(2);
	TMatrix<int> a(2);
	m[0][0] = 1; a[0][0] = 1;
	m[0][1] = 1; a[0][1] = 1;
	m[1][1] = 1; a[1][1] = 1;
     EXPECT_EQ(1, m == a);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{

	TMatrix<int> m(2);
    m[0][0] = 1;
 	m[0][1] = 1;
	m[1][1] = 1;
	EXPECT_EQ(1, m==m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(2);
	TMatrix<int> a(3);
  EXPECT_EQ(1, m!=a);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> a(2);
	TMatrix<int> b(2);
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][1] = 1;
	b[0][0] = 1;
	b[0][1] = 1;
	b[1][1] = 1;
	m[0][0] = 2;
    m[0][1] = 2;
	m[1][1] = 2;


	EXPECT_EQ(m, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> a(3);
	ASSERT_ANY_THROW(m + a);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> a(2);
	TMatrix<int> b(2);
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][1] = 1;
	b[0][0] = 1;
	b[0][1] = 1;
	b[1][1] = 1;
	m[0][0] = 0;
	m[0][1] = 0;
	m[1][1] = 0;
	ASSERT_NO_THROW(m - a);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> a(3);

	ASSERT_ANY_THROW(m - a);
}

