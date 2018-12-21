#include "utmatrix.h"

#include <gtest/gtest.h>

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
	TVector<int> v1(v);
	ASSERT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	TVector<int> v1(v);
	ASSERT_NE(&v, &v1);
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
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-1] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[4] = 4);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	ASSERT_EQ(&v, &(v = v));
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(4), v1(4);
	v1 = v;
	ASSERT_EQ(v, v1);
	ASSERT_NO_THROW(v = v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(4), v1(10);
	v1 = v;
	ASSERT_EQ(v.GetSize(), v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(4), v1(10);
	ASSERT_NO_THROW(v = v1);
	v1 = v;
	ASSERT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(4), v1(v);

	ASSERT_TRUE(v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4), v1(10);
	ASSERT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4), v1(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		v1[i] = i + 120;
	}
	ASSERT_EQ(v + 120, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4), v1(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		v1[i] = i - 120;
	}
	ASSERT_EQ(v - 120, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(4), v1(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		v1[i] = i * 120;
	}
	ASSERT_EQ(v * 120, v1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(4), v1(4), v2(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		v1[i] = i;
		v2[i] = i * 2;
	}
	ASSERT_EQ(v + v1, v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(4), v1(10);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(4), v1(4), v2(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		v1[i] = i;
		v2[i] = 0;
	}
	ASSERT_EQ(v - v1, v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(4), v1(10);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(3), v1(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		v1[i] = i;
	}
	ASSERT_EQ(v * v1, 5);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(3), v1(5);
	ASSERT_ANY_THROW(v * v1);
}
//мои тесты
TEST(TVector, can_add_three_vectors_with_equal_size)
{
	const int size = 5;
	TVector<int> v1(size), v2(size), v3(size), exp_res(size);
	for (int i = 0; i < size; ++i)
	{
		v1[i] = i;
		v2[i] = i * i;
		v3[i] = i + 100;
		exp_res[i] = i + i * i + i + 100;
	}

	EXPECT_EQ(v1 + v2 + v3, exp_res);
}
TEST(TVector, can_add_three_scalars_to_vector)
{
	const int size = 5;
	TVector<int> v(size), exp_res(size);
	for (int i = 0; i < size; ++i)
	{
		v[i] = i;
		exp_res[i] = i + 10 + 20 + 30;
	}

	EXPECT_EQ(v + 10 + 20 + 30, exp_res);
}
TEST(TVector, can_combine_different_operations_with_vector)
{
	const int size = 5;
	TVector<int> v(size), exp_res(size);
	for (int i = 0; i < size; ++i)
	{
		v[i] = i;
		exp_res[i] = (i + 10) * 5 - 20;
	}

	EXPECT_EQ((v + 10) * 5 - 20, exp_res);
}
TEST(TVector, dot_product_can_be_equal_to_zero)
{
	const int size = 2;
	TVector<int> v1(size), v2(size);
	v1[0] = -3; v1[1] = 5;
	v2[0] = 5; v2[1] = 3;

	EXPECT_EQ(v1 * v2, 0);
}
TEST(TVector, can_apply_few_assignment_operators)
{
	const int size = 5;
	TVector<int> v1(size), v2(size), v3(size);
	for (int i = 0; i < size; ++i)
		v1[i] = i * 10;
	v3 = v2 = v1;

	EXPECT_TRUE(v2 == v1);
	EXPECT_TRUE(v3 == v1);
}
