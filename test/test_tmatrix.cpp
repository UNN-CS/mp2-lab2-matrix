#include "utmatrix.h"

#include "gtest.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m(5);
	TMatrix<int> m1(m);
    
    EXPECT_EQ(m,m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m1(5),m2(m1);
    
    EXPECT_NE(&m1[0][0],&m2[0][0]);
}

TEST(TMatrix, can_get_size)
{
  const int size = 7;
  TMatrix<int> m(size);
  
  EXPECT_EQ(size, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  const int size = 5;
  TMatrix<int> m(size);
  m[1][3] = 8;
  
  EXPECT_EQ(8, m[1][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  const int size = 5;
  TMatrix<int> m(size);
  
  ASSERT_ANY_THROW(m[1][-2] = 6);  
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  const int size = 5;
  TMatrix<int> m(size);
  
  ASSERT_ANY_THROW(m[1][6] = 6);  
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    const int size = 5;
    TMatrix<int> m(size);
    
    ASSERT_NO_THROW(m=m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  const int size = 5;
  TMatrix<int> m1(size),m2(size);
  m1[0][4] = 5,m1[3][3] = 9;
  m2 = m1;
  
  EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  const int size1 = 5,size2 = 8;
  TMatrix<int> m1(size1),m2(size2);
  m2 = m1;
  
  EXPECT_EQ(size1, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    const int size1 = 5,size2 = 8;
    TMatrix<int> m1(size1),m2(size2);
    m1[0][4] = 5,m1[3][3] = 9;
    m2 = m1;
    
    EXPECT_EQ(m1, m2); 
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    const int size = 5;
    TMatrix<int> m1(size);
    m1[0][4] = 5,m1[3][4] = 9;
    TMatrix<int> m2(m1);
    
    EXPECT_EQ(true, m1==m2);    
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    const int size = 5;
    TMatrix<int> m1(size);
    m1[0][4] = 5,m1[3][4] = 9;
    
    EXPECT_EQ(true, m1==m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    const int size1 = 5, size2 = 7;
    TMatrix<int> m1(size1),m2(size2);
    
    EXPECT_NE(m1,m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    const int size = 5;
    TMatrix<int> m1(size),m2(size),res(size);
    m1[1][2] = 1; m1[3][3] = 4;
    m2[1][2] = 3; m2[3][3] = 6; m2[4][4] = 1;
    res[1][2] = 4; res[3][3] = 10; res[4][4] = 1;
    
    EXPECT_EQ(res, m1+m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    const int size1 = 5, size2 = 7;
    TMatrix<int> m1(size1),m2(size2);
    
    ASSERT_ANY_THROW(m1+m2);
  
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    const int size = 5;
    TMatrix<int> m1(size),m2(size),res(size);
    m1[1][2] = 1; m1[3][4] = 4; m1[4][4] = 3;
    m2[1][2] = 3; m2[3][4] = 6; m2[4][4] = 10;
    res[1][2] = 2; res[3][4] = 2; res[4][4] = 7;
    
    EXPECT_EQ(res, m2-m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    const int size1 = 5, size2 = 7;
    TMatrix<int> m1(size1),m2(size2);
    
    ASSERT_ANY_THROW(m1-m2);
}

TEST(TMatrix, can_add_matrix_to_itself)
{
	const int size = 5;
    TMatrix<int> m1(size);
    m1[1][2] = 1; m1[3][4] = 4; m1[4][4] = 3;
	TMatrix<int> res(m1);
	
	EXPECT_EQ(res+res, m1+m1);	
}

TEST(TMatrix, can_substract_matrix_to_itself)
{
	const int size = 5;
    TMatrix<int> m1(size),res(size);
    m1[1][2] = 1; m1[3][4] = 4; m1[4][4] = 3;
	
	EXPECT_EQ(res, m1-m1);	
}

TEST(TMatrix, throws_when_get_element_with_wrong_index)
{
	const int size = 5;
    TMatrix<int> m(size);
	
	ASSERT_ANY_THROW(m[4][3]);
}

TEST(TMatrix, cant_set_element_with_wrong_index)
{
	const int size = 5;
    TMatrix<int> m(size);
   
	ASSERT_ANY_THROW(m[3][0] = 3);
}

TEST(TMatrix, different_matrix_is_not_equal)
{
	const int size = 5;
    TMatrix<int> m1(size),m2(size);
    m1[1][2] = 1;
    m2[1][2] = 3;
	
	EXPECT_NE(m1,m2);
} 