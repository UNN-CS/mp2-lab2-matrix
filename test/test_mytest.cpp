#include "utmatrix.h"

#include <gtest.h>

TEST(my_test, cant_add_vectors_with_not_equal_startindex)
{
	TVector <int> v1 (3), v2(3,1);
	ASSERT_ANY_THROW(v1+v2);
}

TEST(my_test, cant_subtract_vectors_with_not_equal_startindex)
{
	TVector <int> v1 (3), v2(3,1);
	ASSERT_ANY_THROW(v1-v2);
}

TEST(my_test, cant_multiply_vectors_with_not_equal_startindex)
{
	TVector <int> v1 (3), v2(3,1);
	ASSERT_ANY_THROW(v1*v2);
}

TEST(my_test, can_assign_vectors_of_different_startindex)
{
	const int size = 5;
	const int startind1 = 2, startind2 = 3;
	TVector<int> v1(size, startind1), v2(size, startind2);
	v1 = v2;

	ASSERT_EQ (v1, v2);
}

TEST(my_test, vectors_with_different_startindex_are_not_equal)
{
	const int size = 5;
	const int startind1 = 2, startind2 = 3;
	TVector<int> v1(size, startind1), v2(size, startind2);

	EXPECT_EQ(false, v1==v2);
}

TEST(my_test, compare_different_vectors_return_false)
{
	const int size = 3;
	TVector<int> v1(size), v2(size);
	v1 [1] = 7;

	EXPECT_EQ(false, v1==v2);
}

TEST(my_test, no_throws_when_add_vectors_with_equal_size)
{
	int size = 4;
	TVector<int> v1(size), v2(size);
	
	ASSERT_NO_THROW (v1+v2);
}

TEST(my_test, no_throws_when_subtract_vectors_with_equal_size)
{
	int size = 4;
	TVector<int> v1(size), v2(size);
	
	ASSERT_NO_THROW (v1-v2);
}

TEST(my_test, no_throws_when_multiply_vectors_with_equal_size)
{
	int size = 4;
	TVector<int> v1(size), v2(size);
	
	ASSERT_NO_THROW (v1*v2);
}

TEST(my_test, cant_create_matrix_with_size_0)
{
	ASSERT_ANY_THROW(TMatrix<int> m(0));
}