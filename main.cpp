#include "sm.h"
#include <gtest/gtest.h>

TEST(SingMagnitudeTest, emptyNumber) {
	smNum a;
	std::vector<uint32_t> zero;
	zero.push_back(0);
	EXPECT_FALSE(a.getSign());
	EXPECT_EQ(a.getModule(), zero);
}

TEST(SingMagnitudeTest, emptyNumber2) {
	unsigned val = 14;
	std::vector<uint32_t> check;
	auto a = smNum(1,val);
	check.push_back(val);
	EXPECT_TRUE(a.getSign());
	EXPECT_EQ(a.getModule(),check);
}

TEST(SingMagnitudeTest, emptyNumber3) {
	unsigned val = 500;
	auto a = natural(val); //natural o wartosci +500
	std::vector<uint32_t> check;
	auto b = smNum(0, a);
	check.push_back(val);
	EXPECT_FALSE(b.getSign());
	EXPECT_EQ(b.getModule(),check);
}
TEST(NaturalTest, decremetZero) {
	std::vector<uint32_t> zero;
	zero.push_back(0);
	auto a = natural(zero);
	EXPECT_THROW(--a, std::runtime_error);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}