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
    v[2] = 5;
    v[8] = 7;
	TVector<int> v1(v);
  
  EXPECT_EQ(v,v1);
}
 TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(10);
  TVector<int> v1(v);
  
  EXPECT_NE(&v[0], &v1[0]);
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
   
   ASSERT_ANY_THROW(v[-2] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(8);
  
  ASSERT_ANY_THROW(v[9] = 4);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(8);
  
  ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
   const int size = 10;
   TVector<int> v1(size),v2(size);
   v1[2] = 5;
   v1[8] = 7;
   v2 = v1;
   
   EXPECT_EQ(v1,v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
  const int size1 = 10, size2 = 20;
  TVector<int> v1(size1),v2(size2);
  v1 = v2;
  
  EXPECT_EQ(v1.GetSize(), size2); 
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  const int size1 = 5,size2 = 8;
  TVector<int> v1(size1),v2(size2);
  for(int i = 0;i<size1;i++)
   v1[i] = i;
  v2 = v1; 
  
  EXPECT_EQ(v1,v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    const int size = 4;
    TVector<int> v1(size),v2(size);
    v1[0] = 1;v1[2] = 3; v1[3] = 4;
    v2=v1;
    
    EXPECT_EQ(true, v1==v2);  
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    const int size = 4;
    TVector<int> v(size);
    
    EXPECT_EQ(true, v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  const int size1 = 5,size2 = 8;
  TVector<int> v1(size1),v2(size2);
  
  EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
  const int size = 4;
  TVector<int> v(size),res(size);
  v[0] = 1; v[1] = 2; v[2] = 3; v[3] = 4;
  res[0] = 6; res[1] = 7; res[2] = 8; res[3] = 9;
  
  EXPECT_EQ(res, v+5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  const int size = 4;
  TVector<int> v(size),res(size);
  v[0] = 3; v[1] = 4; v[2] = 5; v[3] = 6;
  res[0] = 1; res[1] = 2; res[2] = 3; res[3] = 4;
  
  EXPECT_EQ(res, v-2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  const int size = 4;
  TVector<int> v(size),res(size);
  v[0] = 1; v[1] = 2; v[2] = 3; v[3] = 4;
  res[0] = 3; res[1] = 6; res[2] = 9; res[3] = 12;
  
  EXPECT_EQ(res, v*3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  const int size = 4;
  TVector<int> v1(size),v2(size),res(size);
  v1[0] = 1; v1[1] = 2; v1[2] = 3; v1[3] = 4;
  v2[2] = 1; v2[3] = 2;
  res[0] = 1; res[1] = 2; res[2] = 4; res[3] = 6;
  
  EXPECT_EQ(res, v1+v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  const int size1 = 10,size2 = 20;
  TVector<int> v1(size1),v2(size2);
  
  ASSERT_ANY_THROW(v1+v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  const int size = 4;
  TVector<int> v1(size),v2(size),res(size);
  v1[0] = 1; v1[1] = 2; v1[2] = 3; v1[3] = 4;
  v2[2] = 1; v2[3] = 2;
  res[0] = -1; res[1] = -2; res[2] = -2; res[3] = -2;
  
  EXPECT_EQ(res, v2-v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  const int size1 = 10,size2 = 20;
  TVector<int> v1(size1),v2(size2);
  
  ASSERT_ANY_THROW(v1-v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  const int size = 4;
  TVector<int> v1(size),v2(size);
  v1[0] = 1; v1[1] = 2; v1[2] = 3; v1[3] = 4;
  v2[0] = 2; v2[1] = 3; v2[2] = 4; v2[3] = 5;
  
  EXPECT_EQ(40, v1*v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  const int size1 = 10,size2 = 20;
  TVector<int> v1(size1),v2(size2);
  
  ASSERT_ANY_THROW(v1*v2);
}

TEST(TVector, can_add_vector_to_itself)
{
	const int size = 4;
	TVector<int> v(size);
	v[0] = 1; v[1] = 2; v[2] = 3; v[3] = 4;
	TVector<int> res(v);
	EXPECT_EQ(res*2, v+v);
}

TEST(TVector, can_substract_vectors_to_itself)
{
	const int size = 4;
	TVector<int> v(size),res(v);
	v[0] = 10; v[1] = 9; v[2] = 8; v[3] = 7;
	EXPECT_EQ(res*0, v-v);
}

TEST(TVector, can_multiply_vectors_to_itself)
{
	const int size = 4,res = 294;
	TVector<int> v(size);
	v[0] = 10; v[1] = 9; v[2] = 8; v[3] = 7;
	EXPECT_EQ(res, v*v);
}

TEST(TVector, assign_operator_change_vector_startindex)
{
	const int size1 = 5,size2 = 3,start_index = 2;
	TVector<int> v1(size1),v2(size2,start_index);
	v1 = v2;
	
	EXPECT_EQ(start_index, v1.GetStartIndex());
}

TEST(TVector, can_multiply_null_vector)
{
	const int size = 5;
	TVector<int> v(size);
 	EXPECT_EQ(0, v*v);
} 
