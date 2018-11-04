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
	TVector<int> v1(10), v2(v1);

	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<char> v1(3);
	v1[0] = 'a';
	TVector<char> v2(v1);
	v1[0] = 'b';

	EXPECT_EQ(v2[0], 'a');
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
	TVector<int> v1(5);

	ASSERT_ANY_THROW(v1[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v1(5);

	ASSERT_ANY_THROW(v1[10] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	const int size = 3;
	TVector<int> v(size, 1), vt(size, 1);
	// v = (2, 1, 0)
	v[1] = 2;
	v[2] = 1;
	v[3] = 0;
	// vt = (2, 1, 0)
	vt[1] = 2;
	vt[2] = 1;
	vt[3] = 0;
	v = v;

	EXPECT_EQ(vt, v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int size = 3;
	TVector<int> v(size, 1), vt(size, 1);
	// v = (2, 1, 0)
	v[1] = 2;
	v[2] = 1;
	v[3] = 0;
	// vt = (4, -1, 3)
	vt[1] = 4;
	vt[2] = -1;
	vt[3] = 3;
	v = vt;

	EXPECT_EQ(vt, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int sizev = 3, sizevt = 1;
	TVector<int> v(sizev, 1), vt(sizevt, 1);
	// v = (2, 1, 0)
	v[1] = 2;
	v[2] = 1;
	v[3] = 0;
	// vt = (10)
	vt[1] = 10;
	v = vt;

	EXPECT_NE(sizev, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int sizev = 3, sizevt = 1;
	TVector<int> v(sizev, 1), vt(sizevt, 1);
	// v = (2, 1, 0)
	v[1] = 2;
	v[2] = 1;
	v[3] = 0;
	// vt = (10)
	vt[1] = 10;
	v = vt;

	EXPECT_EQ(sizevt, v.GetSize());
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(3), v2(3);
	v1[0] = 2; v2[0] = 2;
	v1[1] = 3; v2[1] = 3;
	v1[2] = 5; v2[2] = 5;

	EXPECT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  ADD_FAILURE();
}

TEST(TVector, can_add_scalar_to_vector)
{
  ADD_FAILURE();
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

