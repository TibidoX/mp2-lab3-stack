#include "../Lab_3/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> m(5);
  ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> m(5);
	TStack<int> mm(m);
	EXPECT_EQ(m, mm);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> m(5);
	TStack<int> mm(m);
	EXPECT_NE(&m, &mm);
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TStack, can_get_size)
{
	TStack<int> m(5);
	EXPECT_EQ(m.GetSize(), 5);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> m(5);
	TStack<int> mm(5);
	m = mm;
	EXPECT_EQ(m, mm);
}

TEST(TStack, assign_operator_change_stack_size)
{
	TStack<int> m(5);
	TStack<int> mm(10);

	m = mm;
	EXPECT_EQ(mm.GetSize(), m.GetSize());
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> m(5);
	TStack<int> mm(10);
	m = mm;
	EXPECT_EQ(m,mm);
}

TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> m(5);
	TStack<int> mm(5);

	EXPECT_EQ(true, m == mm);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
	TStack<int> m(5);

	EXPECT_EQ(true, m == m);
}

TEST(TStack, compare_not_equal_stacks_return_false)
{
	TStack<int> m(5);
	TStack<int> mm(5);
	m.Push(1); mm.Push(-1);

	EXPECT_EQ(false, m == mm);
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
	TStack<int> m(5);
	TStack<int> mm(10);

	EXPECT_EQ(false, m == mm);
}

TEST(TStack, can_push_if_stack_isnt_full)
{
	TStack<int> m(5);
	m.Push(1);

	EXPECT_EQ(m.Pop(), 1);
}

TEST(TStack, cant_push_if_stack_is_full)
{
	TStack<int> m(5);
	for(int i = 0; i < 5; i++)
		m.Push(1);
	ASSERT_ANY_THROW(m.Push(1));
}

TEST(TStack, can_pop_if_stack_isnt_empty)
{
	TStack<int> m(5);
	for (int i = 0; i < 4; i++)
		m.Push(1);
	EXPECT_EQ(m.Pop(), 1);
}

TEST(TStack, cant_pop_if_stack_is_empty)
{
	TStack<int> m(5);
	ASSERT_ANY_THROW(m.Pop());
}
//TEST(TMatrix, can_set_and_get_element)
//{
//	TMatrix<int> m(5);
//	m[0][0] = 1;
//	EXPECT_EQ(1, m[0][0]);
//}
//
//TEST(TMatrix, throws_when_set_element_with_negative_index)
//{
//	TMatrix<int> m(5);
//	ASSERT_ANY_THROW(m[-1] = 1);
//}
//
//TEST(TMatrix, throws_when_set_element_with_too_large_index)
//{
//	TMatrix<int> m(5);
//	ASSERT_ANY_THROW(m[5] = 1);
//}
//

//

//

//}
//

//}
//
//TEST(TMatrix, matrices_with_different_size_are_not_equal)
//{
//	TMatrix<int> m(5);
//	TMatrix<int> mm(10);
//
//	EXPECT_EQ(false, m == mm);
//}
//
//TEST(TMatrix, can_add_matrices_with_equal_size)
//{
//	TMatrix<int> m(3);
//	TMatrix<int> mm(3);
//	TMatrix<int> res(3);
//	for (int i = 0; i < 3; i++)
//		for (int j = i; j < 3; j++)
//		{
//			m[i][j] = 1;
//			mm[i][j] = 2;
//			res[i][j] = 3;
//		}
//	EXPECT_EQ(m + mm,res);
//}
//
//TEST(TMatrix, cant_add_matrices_with_not_equal_size)
//{
//	TMatrix<int> m(5);
//	TMatrix<int> mm(10);
//
//	ASSERT_ANY_THROW(m + mm);
//}
//
//TEST(TMatrix, can_subtract_matrices_with_equal_size)
//{
//	TMatrix<int> m(3);
//	TMatrix<int> mm(3);
//	TMatrix<int> res(3);
//	for (int i = 0; i < 3; i++)
//		for (int j = i; j < 3; j++)
//		{
//			m[i][j] = 1;
//			mm[i][j] = 2;
//			res[i][j] = -1;
//		}
//	EXPECT_EQ(m - mm, res);
//}
//
//TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
//{
//	TMatrix<int> m(5);
//	TMatrix<int> mm(10);
//
//	ASSERT_ANY_THROW(m - mm);
//}

