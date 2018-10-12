#include "utmatrix.h"

#include "gtest.h"

TEST(TVector, vectors_with_different_start_position_are_not_equal)
{
	TVector<int> v(4, 0), w(4, 2);

	ASSERT_EQ(1, v != w);
}

TEST(TVector, cant_add_vectors_with_not_equal_start_position)
{
	TVector<int> v(4, 0), w(4, 2);

	ASSERT_ANY_THROW(v + w);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_start_position)
{
	TVector<int> v(4, 0), w(4, 2);

	ASSERT_ANY_THROW(v - w);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_start_position)
{
	TVector<int> v(4, 0), w(4, 2);

	ASSERT_ANY_THROW(v*w);
}

TEST(TVector, throw_when_set_element_on_position_smaller_than_start_index)
{
	TVector<int> v(4, 2);

	ASSERT_ANY_THROW(v[1]);
}

TEST(TMatrix, cant_get_element_in_lower_triangle)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[3][1]);
}

TEST(TMatrix, memory_of_main_vector_of_copied_matrix_are_not_equal_to_this_in_original)
{
	TMatrix<int> m(4);
	TMatrix<int> mx(m);

	ASSERT_NE(&mx[0], &m[0]);
}

TEST(TMatrix, can_assign_matrixs_in_sequence)
{
	TMatrix<int> a(2), b(5), c(7);

	ASSERT_NO_THROW(a = b = c);
}

TEST(TMatrix, can_add_matrixs_in_sequence)
{
	TMatrix<int> a(5), b(5), c(5);

	ASSERT_NO_THROW(a + b + c);
}

TEST(TMatrix, can_subtract_matrixs_in_sequence)
{
	TMatrix<int> a(5), b(5), c(5);

	ASSERT_NO_THROW(a - b - c);
}
