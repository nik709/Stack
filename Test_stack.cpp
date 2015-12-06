#include "stdafx.h"
#include "gtest.h"
#include "TStack.h"

TEST(Tstack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Tstack <int> stack(5));
}

TEST(Tstack, can_not_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Tstack <int> stack(-5));
}

TEST(Tstack, can_create_stack_by_default)
{
	ASSERT_NO_THROW(Tstack <int> stack());
}

TEST(Tstack, can_create_copied_stack)
{
	Tstack <int> stack(5);
	ASSERT_NO_THROW(Tstack <int> stack1(stack));
}

TEST(Tstack, can_assign_stacks_of_equal_size)
{
	Tstack <int> stack(5);
	Tstack <int> stack1(5);
	stack.Push(1);
	stack1 = stack;
	bool flag = true;
	for (int i = 0; i < 5; i++)
	{
		if (stack1.Top() != stack.Top())
		{
			flag = false;
			break;
		}
	}
	EXPECT_EQ(true, flag);
}

TEST(Tstack, can_assign_stacks_of_different_size)
{
	Tstack <int> stack(5);
	Tstack <int> stack1(4);
	stack.Push(1);
	stack1 = stack;
	bool flag = true;
	for (int i = 0; i < 5; i++)
	{
		if (stack1.Top() != stack.Top())
		{
			flag = false;
			break;
		}
	}
	EXPECT_EQ(true, flag);
}

TEST(Tstack, can_check_the_empty_when_stack_is_empty)
{
	Tstack <int> stack(5);
	bool flag = stack.IsEmpty();
	EXPECT_EQ(true, flag);
}

TEST(Tstack, can_check_the_empty_when_stack_is_not_empty)
{
	Tstack <int> stack(5);
	stack.Push(1);
	bool flag = stack.IsEmpty();
	EXPECT_EQ(false, flag);
}

TEST(Tstack, can_check_the_full_when_stack_is_full)
{
	Tstack <int> stack(5);
	for (int i = 0; i < 5; i++)
		stack.Push(1);
	bool flag = stack.IsFull();
	EXPECT_EQ(true, flag);
}

TEST(Tstack, can_check_the_full_when_stack_is_not_full)
{
	Tstack <int> stack(5);
	for (int i = 0; i < 4; i++)
		stack.Push(1);
	bool flag = stack.IsFull();
	EXPECT_EQ(false, flag);
}

TEST(Tstack, can_look_at_the_top)
{
	Tstack <int> stack(5);
	stack.Push(1);
	EXPECT_EQ(1, stack.Top());
}

TEST(Tstack, can_get_element_from_the_top_of_the_stack)
{
	Tstack <int> stack(5);
	stack.Push(1);
	int elem = stack.Pop();
	EXPECT_EQ(1, elem);
}

TEST(Tstack, can_push_element_to_the_stack)
{
	Tstack <int> stack(5);
	stack.Push(1);
	EXPECT_EQ(1, stack.Top());
}

TEST(Tstack, can_not_push_element_to_the_full_stack)
{
	Tstack <int> stack(5);
	for (int i = 0; i < 5; i++)
		stack.Push(1);
	ASSERT_ANY_THROW(stack.Push(1));
}

TEST(Tstack, can_clear_stack)
{
	Tstack <int> stack(5);
	stack.Push(1);
	bool flag = stack.IsEmpty();
	EXPECT_EQ(false, flag);
	stack.clear();
	flag = stack.IsEmpty();
	EXPECT_EQ(true, flag);
}