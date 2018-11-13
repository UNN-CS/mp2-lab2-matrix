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
	const int size = 5;
	TVector<int> v1(size), v2(size);

	v1[2] = 7;
	v2 = v1;

	ASSERT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(10), v2(v1);
	v2 [2] = 7;

	ASSERT_NE(v1, v2);
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
	TVector<int> v(2);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(2);
	ASSERT_ANY_THROW(v[3]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v1(10);

	ASSERT_NO_THROW(TVector<int> v2 = v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int size = 3;
	TVector<int> v1(size), v2(size);
	for (int i=0; i<size; i++)
		v1[i] = 2;
	v2 = v1;

	EXPECT_NE(0 , v2[0]);
	EXPECT_NE(0 , v2[1]);
	EXPECT_NE(0 , v2[2]);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int size1 = 2, size2 = 5;
	TVector<int> v1(size1), v2(size2);
	v2 = v1;

	EXPECT_EQ(2, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int size1 = 2, size2 = 3;
	TVector<int> v1(size1), v2(size2);
	v1 = v2;
	
	ASSERT_EQ (v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	const int size = 3;
	TVector<int> v1(size), v2(size);

	EXPECT_EQ(true, v1==v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);

	EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	const int size1 = 3, size2 = 5;
	TVector<int> v1(size1), v2(size2);

	EXPECT_EQ(false, v1==v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	const int sc = 5;
	v = v + sc;

	EXPECT_EQ(5 , v[0]);
	EXPECT_EQ(5 , v[1]);
	EXPECT_EQ(5 , v[2]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4);
	const int sc = 5;
	v = v - sc;

	EXPECT_EQ(-5 , v[0]);
	EXPECT_EQ(-5 , v[1]);
	EXPECT_EQ(-5 , v[2]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(4);
	const int sc = 5;
	for (int i=0; i<4; i++)
		v[i] = 2;
	v = v * sc;

	EXPECT_EQ(10 , v[0]);
	EXPECT_EQ(10 , v[1]);
	EXPECT_EQ(10 , v[2]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int size = 4;
	TVector<int> v1(size), v2(size);
	for (int i=0; i<size; i++)
		v1[i] = 2;
	for (int i=0; i<size; i++)
		v2[i] = 3;
	TVector<int> v3 = v1 + v2;
  
	EXPECT_EQ(5 , v3[0]);
	EXPECT_EQ(5 , v3[1]);
	EXPECT_EQ(5 , v3[2]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	int size1 = 4, size2 = 6;
	TVector<int> v1(size1), v2(size2);
  
	ASSERT_ANY_THROW (v1+v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int size = 4;
	TVector<int> v1(size), v2(size);
	for (int i=0; i<size; i++)
		v1[i] = 3;
	for (int i=0; i<size; i++)
		v2[i] = 2;
	TVector<int> v3 = v1 - v2;
  
	EXPECT_EQ(1 , v3[0]);
	EXPECT_EQ(1 , v3[1]);
	EXPECT_EQ(1 , v3[2]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	int size1 = 4, size2 = 6;
	TVector<int> v1(size1), v2(size2);
  
	ASSERT_ANY_THROW (v1-v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int size = 4;
	TVector<int> v1(size), v2(size);
	for (int i=0; i<size; i++)
		v1[i] = 1;
	for (int i=0; i<size; i++)
		v2[i] = 2;
 
	EXPECT_EQ(8 , v1*v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	int size1 = 4, size2 = 6;
	TVector<int> v1(size1), v2(size2);
  
	ASSERT_ANY_THROW (v1*v2);
}

