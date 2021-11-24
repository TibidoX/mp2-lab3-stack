#include "../Lab_3/TCalculator.h"
#include "gtest.h"

#include  <string>

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator c("(1+1)"));
}

TEST(TCalculator, can_create_copied_calculator)
{
	TCalculator c("1+2*(3-2)-4");
	ASSERT_NO_THROW(TCalculator c1(c));
}

TEST(TCalculator, copied_stack_is_equal_to_source_one)
{
	TCalculator c("1+2*(3-2)-4");
	TCalculator c1(c);
	EXPECT_EQ(c, c1);
}

TEST(TCalculator, copied_calculator_has_its_own_memory)
{
	TCalculator c("1+2*(3-2)-4");
	TCalculator c1(c);
	EXPECT_NE(&c, &c1);
}

TEST(TCalculator, can_assign_to_itself)
{
	TCalculator c("1+2*(3-2)-4");
	ASSERT_NO_THROW(c = c);
}

TEST(TCalculator, can_get_postfix)
{
	TCalculator c("1+2*(3-2)-4");
	c.ToPostfix();
	EXPECT_EQ("1232-*+4-", c.GetP());
}

TEST(TCalculator, can_calculate_with_postfix)
{
	TCalculator c("1+2*(3-2)-4");
	c.ToPostfix();
	EXPECT_EQ(c.calc(), -1);
}

TEST(TCalculator, can_calculate_without_postfix)
{
	TCalculator c("1+2*(3-2)-4");
	EXPECT_EQ(c.calcInfix(), -1);
}

TEST(TCalculator, can_set_and_get_expr)
{
	TCalculator c;
	c.SetE("1+2*(3-2)-4");
	EXPECT_EQ(c.GetE(), "1+2*(3-2)-4");
}
