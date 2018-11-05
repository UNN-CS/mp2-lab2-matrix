#include "utmatrix.h"

#include <gtest.h>

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
	TVector<int> v(3);
	//v = (4, 3, -2)
	v[0] = 4;
	v[1] = 3;
	v[2] = -2;
	TVector<int> vt(v);

	EXPECT_EQ(v, vt);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(3);
	//v = (1, 1, -1)
	v[0] = 1;
	v[1] = 1;
	v[2] = -1;

	TVector<int> vt(v);
	TVector<int> *p, *pt;
	p = &v;
	pt = &vt;

	EXPECT_NE(p, pt);
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
	TVector<int> v(4,1);
	v[2] = 4;

	EXPECT_EQ(4, v[2]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);

	ASSERT_ANY_THROW(v[-1] = 3);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);

	ASSERT_ANY_THROW(v[7] = 3);
}

TEST(TVector, can_assign_vector_to_itself)
{
	const int size = 3;
	TVector<int> v(size,1), vt(size,1);
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
	TVector<int> v(size,1), vt(size,1);
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
	TVector<int> v(sizev,1), vt(sizevt,1);
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
	TVector<int> v(sizev,1), vt(sizevt,1);
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
	TVector<int> v1(3);
	//v1 = (2, 3, 5)
	v1[0] = 2;
	v1[1] = 3;
	v1[2] = 5;

	EXPECT_TRUE(v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(3), v2(4);
	//v1 = (0, 0, 0)
	//v2 = (0, 0, 0, 0)
	v1[0] = 0; v2[0] = 0;
	v1[1] = 0; v2[1] = 0;
	v1[2] = 0; v2[2] = 0;
			   v2[3] = 0;

	EXPECT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	const int size = 5, si = 2;
	const int val = 10;
	TVector<int> v(size, si), vt(size, si);
	//v1 = (1, 3, 5, 8, 13)
	v[0 + si] = 1;
	v[1 + si] = 3;
	v[2 + si] = 5;
	v[3 + si] = 8;
	v[4 + si] = 13; 
	//vt = (11, 13, 15, 18, 23)
	for (int i = si; i < size + si; i++)
		vt[i] = v[i] + val;

	EXPECT_EQ(vt, v + val);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  	const int size = 5, si = 0;
	const int val = 5;
	TVector<int> v(size, si), vt(size, si);
	//v1 = (6, 4, 11, 9, 20)
	v[0 + si] = 6;
	v[1 + si] = 4;
	v[2 + si] = 11;
	v[3 + si] = 9;
	v[4 + si] = 20;
	//vt = (1, -1, 6, 4, 15)
	for (int i = si; i < size + si; i++)
		vt[i] = v[i] - val;

	EXPECT_EQ(vt, v - val);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	const int size = 5, si = 1;
	const int val = 3;
	TVector<int> v(size, si), vt(size, si);
	//v1 = (0, -2, 5, 9, -3)
	v[0 + si] = 0;
	v[1 + si] = -2;
	v[2 + si] = 5;
	v[3 + si] = 9;
	v[4 + si] = -3;
	//vt = (0, -6, 15, 27, -9)
	for (int i = si; i < size + si; i++)
		vt[i] = v[i] * val;

	EXPECT_EQ(vt, v * val);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	const int size = 4, si = 2;
	TVector<int> v1(size, si), v2(size, si), vt(size, si);
	//v1 = (6, 11, -4, 0)
	v1[0 + si] = 6;
	v1[1 + si] = 11;
	v1[2 + si] = -4;
	v1[3 + si] = 0;
	//v1 = (-12, -3, 8, 15)
	v2[0 + si] = -12;
	v2[1 + si] = -3;
	v2[2 + si] = 8;
	v2[3 + si] = 15;
	//vt = (-6, 8, 4, 15)
	for (int i = 0; i < size; i++)
		vt[i+si] = v1[i+si] + v2[i+si];

	EXPECT_EQ(vt, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(4);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	const int size = 4, si = 0;
	TVector<int> v1(size, si), v2(size, si), vt(size, si);
	//v1 = (6, 11, -4, 0)
	v1[0 + si] = 6;
	v1[1 + si] = 11;
	v1[2 + si] = -4;
	v1[3 + si] = 0;
	//v1 = (-12, -3, 8, 15)
	v2[0 + si] = -12;
	v2[1 + si] = -3;
	v2[2 + si] = 8;
	v2[3 + si] = 15;
	//vt = (18, 14, -12, -15)
	for (int i = 0; i < size; i++)
		vt[i + si] = v1[i + si] - v2[i + si];

	EXPECT_EQ(vt, v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(4);

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	const int size = 4, si = 1;
	int scal = 0;
	TVector<int> v1(size, si), v2(size, si);
	//v1 = (6, 11, -4, 0)
	v1[0 + si] = 6;
	v1[1 + si] = 11;
	v1[2 + si] = -4;
	v1[3 + si] = 0;
	//v1 = (-2, 6, 8, 15)
	v2[0 + si] = -2;
	v2[1 + si] = 6;
	v2[2 + si] = 8;
	v2[3 + si] = 15;
	//scal = 22
	for (int i = 0; i < size; i++)
		scal += v1[i + si] * v2[i + si];

	EXPECT_EQ(scal, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(4);

	ASSERT_ANY_THROW(v1 * v2);
}

