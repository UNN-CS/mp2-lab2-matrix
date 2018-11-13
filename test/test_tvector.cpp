#include "utmatrix.h"
#include "gtest.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	TVector<int> vcopy(v);
	ASSERT_EQ(v, vcopy);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	TVector<int> vcopy(v);
	vcopy[2] = 5;
	ASSERT_NE(v[2], vcopy[2]);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;
	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(3);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(3);
	ASSERT_ANY_THROW(v[3]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(3);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(3);
	u[0] = 2, u[1] = 3, u[2] = 4;
	u = v;
	ASSERT_EQ(u, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(4);
	u[0] = 2, u[1] = 3, u[2] = 4, u[3] = 5;
	u = v;
	ASSERT_EQ(u, v);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(4);
	u[0] = 2, u[1] = 3, u[2] = 4, u[3] = 5;
	v = u;
	ASSERT_EQ(u, v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(3);
	u[0] = 1, u[1] = 2, u[2] = 3;
	EXPECT_EQ(u, v);
	u[2] = 4;
	EXPECT_NE(u, v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	ASSERT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(3), u(4);
	ASSERT_NE(u, v);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> expected(3);
	for (int i = 0; i < 3; ++i)
		expected[i] = v[i] + 2;
	v = v + 2;
	ASSERT_EQ(v, expected);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> expected(3);
	for (int i = 0; i < 3; ++i)
		expected[i] = v[i] - 2;
	v = v - 2;
	ASSERT_EQ(v, expected);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> expected(3);
	for (int i = 0; i < 3; ++i)
		expected[i] = v[i] * 2;
	v = v * 2;
	ASSERT_EQ(v, expected);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(3);
	u[0] = 3, u[1] = 4, u[2] = 5;
	TVector<int> expected(3);
	expected[0] = 4, expected[1] = 6, expected[2] = 8;
	ASSERT_EQ(expected, u + v);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(4);
	u[0] = 3, u[1] = 4, u[2] = 5, u[3] = 6;
	ASSERT_ANY_THROW(u + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(3);
	u[0] = 3, u[1] = 4, u[2] = 5;
	TVector<int> expected(3);
	expected[0] = -2, expected[1] = -2, expected[2] = -2;
	ASSERT_EQ(expected, v - u);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(4);
	u[0] = 3, u[1] = 4, u[2] = 5, u[3] = 6;
	ASSERT_ANY_THROW(u - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(3);
	u[0] = 3, u[1] = 4, u[2] = 5;
	ASSERT_EQ(26, u * v);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	v[0] = 1, v[1] = 2, v[2] = 3;
	TVector<int> u(4);
	u[0] = 3, u[1] = 4, u[2] = 5, u[3] = 6;
	ASSERT_ANY_THROW(u * v);
}
