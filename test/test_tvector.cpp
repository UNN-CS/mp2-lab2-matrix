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
	TVector <int> a(10);
	   for (int i = 0; i < 5; i++)
		   {
			   a[i] = i * 10 ;
		   }
	 TVector <int> b(a);
	 EXPECT_EQ(b, a);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector <int> a(10);
	for (int i = 0; i < 8; ++i)
		a[i] = 8;
	TVector <int> b(a);
	EXPECT_NE(&a[0],&b[0]);
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
	TVector <int> a(5);
	ASSERT_ANY_THROW(a[-1] = 0);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector <int> a(5);
	ASSERT_ANY_THROW(a[6] = 0);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector <int> v(3);
	v[0] = 6; v[2] = 6; v[1] = 7;
	ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector <int> v(3);
	v[0] = 6; v[2] = 6; v[1] = 7;
	TVector <int> u(3);
	ASSERT_NO_THROW(v = u);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(4), a(2);
	v = a;

	ASSERT_EQ(2, v.GetSize());
}


TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> a(3),b(5);
	ASSERT_NO_THROW(a=b);

}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector <int> a(10),b(10);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
		b[i] = i * 10;
	}
	EXPECT_EQ(1,(b==a));
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector <int> a(10);
	for (int i = 0; i < 5; i++)
		a[i] = i * 10;
	EXPECT_EQ(a,a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector <int> a(10), b(20);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
		b[i] = i * 10;
	}
	EXPECT_EQ(0, (b == a));
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector <int> a(5);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_NO_THROW(a + 5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector <int> a(5);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_NO_THROW(a - 5);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector <int> a(5);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_NO_THROW(a*5);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector <int> a(5),b(5);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_NO_THROW(a +b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector <int> a(5), b(7);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector <int> a(5), b(5);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_NO_THROW(a - b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector <int> a(5), b(7);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector <int> a(5), b(5);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_NO_THROW(a * b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector <int> a(5), b(7);
	for (int i = 0; i < 5; ++i) a[i] = i;
	ASSERT_ANY_THROW(a * b);
}

TEST(TVector, right_multiply_vectors)
{
	TVector <int> a(5), b(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
		b[i] = 5;
	}
	ASSERT_EQ(a * b,50);
	
}

TEST(TVector, right_multiply_vector_and_scalar)
{
	TVector <int> a(5),b(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
		b[i] = i * 5;
	}
	ASSERT_EQ(a * 5, b);
	
}

TEST(TVector, right_add_vectors)
{
	TVector <int> a(5), b(5),c(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
		b[i] = 2*i;
		c[i] = 3 * i;
	}
	ASSERT_EQ(a +b, c);	
}


TEST(TVector, right_subtract_vectors)
{
	TVector <int> a(5), b(5), c(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
		b[i] = 2 * i;
		c[i] = 3 * i;
	}
	ASSERT_EQ(c-a, b);
}

TEST(TVector, right_add_vector_and_scalar)
{
	TVector <int> a(5), b(5), c(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
		b[i] = i+5;
	}
	ASSERT_EQ(a+5, b);	
}

TEST(TVector, right_subtract_vector_and_scalar)
{
	TVector <int> a(5), b(5), c(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
		b[i] = i - 5;
	}
	ASSERT_EQ(a -5, b);
	
}