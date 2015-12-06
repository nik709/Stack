#include "stdafx.h"
#include "gtest.h"
#include "Tparser.h"

TEST(TParser, can_create_parser)
{
	char st[6] = { '2', '+', '5', '*', '2', '\0' };
	ASSERT_NO_THROW(TParser parser(st));
}

TEST(TParser, can_full_calc)
{
	char st[6] = { '3', '+', '5', '*', '2', '\0' };
	TParser parser(st);
	double res = parser.FullCalc();
	EXPECT_EQ(13, res);
}

TEST(TParser, can_full_calc_with_brace)
{
	char st[8] = {'(', '3', '+', '5', ')', '*', '2', '\0' };
	TParser parser(st);
	double res = parser.FullCalc();
	EXPECT_EQ(16, res);
}

TEST(TParser, can_calc_post)
{
	char st[6] = { '3', '+', '5', '*', '2', '\0' };
	TParser parser(st);
	parser.InfToPost();
	double res = parser.CalcPost();
	EXPECT_EQ(13, res);
}

TEST(TParser, can_calc_post_with_brace)
{
	char st[8] = { '(', '3', '+', '5', ')', '*', '2', '\0' };
	TParser parser(st);
	parser.InfToPost();
	double res = parser.CalcPost();
	EXPECT_EQ(16, res);
}


