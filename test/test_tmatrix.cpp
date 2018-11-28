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
	TMatrix<int> m(5), m1(m);
	EXPECT_EQ(true, m == m1);
	//ADD_FAILURE();
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5), t(m);
	EXPECT_NE(&m[0], &t[0]);
	//ADD_FAILURE();
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());

	//ADD_FAILURE();
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[0][0] = 15;
	EXPECT_EQ(15, m[0][0]);
	//ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	EXPECT_ANY_THROW(m[0][-2] = 15;);
	//ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	EXPECT_ANY_THROW(m[0][5] = 15;);
	//ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	EXPECT_NO_THROW(m = m);
	//ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> t(5);

	EXPECT_NO_THROW(m = t);
	//ADD_FAILURE();
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	TMatrix<int> t(6);
	m = t;
	EXPECT_EQ(6, m.GetSize());
	//ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5); m[0][0] = 1;
	TMatrix<int> t(6); t[0][0] = 15;
	m = t;
	//EXPECT_EQ(15, m[0][0]);
	ASSERT_NO_THROW(m = t);
	//ADD_FAILURE();
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(2), t(2);
	m[0][1] = 15; t[0][1] = 15;
	EXPECT_EQ(true, m == t);
	//ADD_FAILURE();
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix <int> m(5);
	EXPECT_EQ(true, m == m);
	//ADD_FAILURE();
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix <int> m(5), t(6);
	EXPECT_EQ(false, m == t);
	//ADD_FAILURE();
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix <int> m(5), t(5);
	EXPECT_NO_THROW(m + t);

	//ADD_FAILURE();
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix <int> m(5), t(6);
	EXPECT_ANY_THROW(m + t);
	//	ADD_FAILURE();
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix <int> m(5), t(5);
	EXPECT_NO_THROW(m - t);
	//ADD_FAILURE();
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix <int> m(5), t(6);
	EXPECT_ANY_THROW(m - t);
	//ADD_FAILURE();
}

