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
	TVector<int> a(2);
	a[0] = 0; a[1] = 10;
	TVector<int> b(a);
	EXPECT_EQ(a, b);
	//ADD_FAILURE();
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> a(2);
	a[0] = 0; a[1] = 10;
	TVector<int> b(a);
	EXPECT_NE(&a[0], &b[0]);

	//ADD_FAILURE();
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
	ASSERT_ANY_THROW(v[-1] = 0);

	//ADD_FAILURE();
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[4] = 0);

	//ADD_FAILURE();
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	ASSERT_NO_THROW(v = v);
	//ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> a(4);
	TVector<int> b(4);
	a[0] = -1;
	b[0] = 0;
	a = b;

	EXPECT_EQ(b, a);
	//ADD_FAILURE();
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(1);
	TVector<int> v2(4);
	v1 = v2;
	EXPECT_EQ(v2.GetSize(), v1.GetSize());
	//ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(4);
	TVector<int> v2(2);
	v1 = v2;
	EXPECT_EQ(v1, v2);
	//ADD_FAILURE();
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(4);
	//v1[0] = 0; v1[1] = 1; v1[2] = 2; v1[3] = 3;
	TVector<int> v2(v1);
	EXPECT_EQ(true, v1 == v2);
	//ADD_FAILURE();
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	EXPECT_EQ(true, v == v);
	//ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	EXPECT_EQ(false, v1 == v2);
	//ADD_FAILURE();
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(4);
	v1[0] = 0; v1[1] = 1; v1[2] = 2; v1[3] = 3;
	TVector<int> v2(4);
	v2[0] = 1; v2[1] = 2; v2[2] = 3; v2[3] = 4;
	EXPECT_EQ(v2, v1 + 1);
	//ADD_FAILURE();
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(4);
	v1[0] = 0; v1[1] = 1; v1[2] = 2; v1[3] = 3;
	TVector<int> v2(4);
	v2[0] = 1; v2[1] = 2; v2[2] = 3; v2[3] = 4;
	EXPECT_EQ(v1, v2 - 1);
	//ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(4);
	v1[0] = 0; v1[1] = 1; v1[2] = 2; v1[3] = 3;
	TVector<int> v2(4);
	v2[0] = 0; v2[1] = 2; v2[2] = 4; v2[3] = 6;
	EXPECT_EQ(v2, v1 * 2);
	//ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(4);
	v1[0] = 0; v1[1] = 1; v1[2] = 2; v1[3] = 3;
	TVector<int> v2(4);
	v2[0] = 0; v2[1] = 2; v2[2] = 4; v2[3] = 6;
	TVector<int> v3(4);
	v3[0] = 0; v3[1] = 3; v3[2] = 6; v3[3] = 9;
	EXPECT_EQ(v3, v1 + v2);
	//ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	EXPECT_ANY_THROW(v1 + v2);
	//ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(4);
	v1[0] = 0; v1[1] = 3; v1[2] = 6; v1[3] = 9;
	TVector<int> v2(4);
	v2[0] = 0; v2[1] = 1; v2[2] = 2; v2[3] = 3;
	TVector<int> v3(4);
	v3[0] = 0; v3[1] = 2; v3[2] = 4; v3[3] = 6;
	EXPECT_EQ(v3, v1 - v2);
	//ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	EXPECT_ANY_THROW(v1 - v2);
	//ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(4);
	v1[0] = 0; v1[1] = 3; v1[2] = 6; v1[3] = 9;
	TVector<int> v2(4);
	v2[0] = 0; v2[1] = 1; v2[2] = 2; v2[3] = 3;

	EXPECT_EQ(42, v1 * v2);//0+3+12+27=42
	//ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	v1[0] = 0; v1[1] = 3; v1[2] = 6; v1[3] = 9; v1[4] = 0;
	TVector<int> v2(4);
	v2[0] = 0; v2[1] = 1; v2[2] = 2; v2[3] = 3;
	EXPECT_ANY_THROW(v1 * v2);
	//ADD_FAILURE();
}