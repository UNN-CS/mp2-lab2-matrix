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
	m[4][4] = 1;
	m[1][3] = 6;
	TMatrix<int> mcopy(m);
	ASSERT_EQ(m, mcopy);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> mcopy(m);
	mcopy[2][2] = 7;
	ASSERT_NE(mcopy[2][2], m[2][2]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);
	ASSERT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[4][4] = 1;
	ASSERT_EQ(1, m[4][4]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-4][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	int s = 8;
	TMatrix<int>m(s);
	ASSERT_ANY_THROW(m[8][8] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), n(5);
	ASSERT_NO_THROW(m = n);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5), n(6);
	m = n;
	ASSERT_NO_THROW(m[0][5] = 1);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), n(6);
	n[4][5] = 1;
	n[5][5] = 2;
	m = n;
	EXPECT_EQ(m[4][5], 1);
	ASSERT_EQ(m[5][5], 2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5), n(5);
	ASSERT_EQ(m, n);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	ASSERT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), n(6);
	ASSERT_NE(m, n);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			expans[i][j] = 3;
		}
	ans = m1 + m2;
	EXPECT_EQ(ans, expans);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), n(6);
	ASSERT_ANY_THROW(m + n);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	
	int s = 7;
	TMatrix<int>m1(s), m2(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = 2 ;
			m2[i][j] = 1;
			expans[i][j] = 1;
		}

	EXPECT_EQ(m1-m2, expans);

}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), n(6);
	ASSERT_ANY_THROW(m - n);
}



TEST(MyTMatrix, throws_when_set_element_in_lower_triangle)
{
	int s = 2;
	TMatrix<int>m(s);
	ASSERT_ANY_THROW(m[1][0] = 5);
}

TEST(MyTMatrix, can_assign_three_matrix)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			expans[i][j] = i * j;

		}
	m3 = m2 = m1;
	EXPECT_EQ(expans, m1);
	EXPECT_EQ(expans, m2);
	EXPECT_EQ(expans, m3);
}

TEST(MyTMatrix, operator_not_equal_return_false_with_equal_matrix)
{
	int s = 6;
	TMatrix<int>m(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m[i][j] = i * j;
	EXPECT_FALSE(m != m);
}


TEST(MyTMatrix, can_subtract_three_matrix_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = 6 * i * j;
			m2[i][j] = 2 * i * j;
			m3[i][j] = 3 * i * j;
			expans[i][j] = i * j;
		}
	ans = m1 - m2 - m3;
	EXPECT_EQ(ans, expans);
}


TEST(MyTMatrix, can_add_three_matrix_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = 2 * i * j;
			m3[i][j] = 3 * i * j;
			expans[i][j] = 6 * i * j;
		}
	ans = m1 + m2 + m3;
	EXPECT_EQ(ans, expans);
}

TEST(MyTMatrix, can_compare_two_vectors_in_matrices)
{
	TMatrix<int> m1(3), m2(3);

	for (int i = 0; i < 3; i++)
		m1[0][i] = m2[0][i];
	ASSERT_TRUE(m1[0] == m2[0]);
}

