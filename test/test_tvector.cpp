
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
TVector<int> A(3);
A[1] = 0;
A[2] = 1;
TVector<int> copyA(A);
EXPECT_EQ(A,copyA);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
TVector<int> A(3);
A[1] = 0;
A[2] = 1;
TVector<int> copyA(A);
EXPECT_NE(&A[0], &copyA[0]);
}

TEST(TVector, can_get_size)
{
TVector<int> A(3);
A[1] = 0;
A[2] = 1;
EXPECT_EQ (3,A.GetSize());
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
EXPECT_ANY_THROW(v[-5]=0);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
TVector<int> v(4);
EXPECT_ANY_THROW(v[4] = 0);
}

TEST(TVector, can_assign_vector_to_itself)
{
TVector<int> v(4);
TVector<int>a;
EXPECT_NO_THROW(a=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
TVector<int> v(4);
TVector<int>a(4);
EXPECT_NO_THROW(a = v);
}

TEST(TVector, assign_operator_change_vector_size)
{
TVector<int> m(5);
TVector<int> a(7);
a = m;
EXPECT_EQ(5, a.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
TVector<int> m(5);
TVector<int> a(7);
m[0] = 1;
m[1] = 2;
m[2] = 4;
m[3] = 4;
m[4] = 4;
a = m;
EXPECT_EQ(1, a == m);
}

TEST(TVector, compare_equal_vectors_return_true)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>b(a);
EXPECT_EQ(a, b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
EXPECT_EQ(a, a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
TVector<int>a(4); TVector<int>b(5);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
EXPECT_NE(a, b);
}

TEST(TVector, can_add_scalar_to_vector)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
EXPECT_NO_THROW(a+2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
EXPECT_NO_THROW(a - 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
EXPECT_NO_THROW(a*2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>v(4);
EXPECT_NO_THROW(a+v);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>v(5);
EXPECT_ANY_THROW(a + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>v(4);
EXPECT_NO_THROW(a-v);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>v(5);
EXPECT_ANY_THROW(a -v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
TVector<int>a(4);
a[0] = 2;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>v(4);
v[0] = 2;
v[1] = 1;
v[2] = 1;
v[3] = 1;

EXPECT_EQ(7,a*v);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
TVector<int>a(4);
a[0] = 1;
a[1] = 1;
a[2] = 1;
a[3] = 1;
TVector<int>v(5);
EXPECT_ANY_THROW(a*v);
}