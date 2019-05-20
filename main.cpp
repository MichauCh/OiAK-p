#include "sm.h"
#include <gtest/gtest.h>

TEST(NaturalTest, initWithZero) {
	auto a = natural(0);
	EXPECT_TRUE(a.isZero());
	std::vector<uint32_t> zero;
	zero.push_back(0);
	EXPECT_EQ(a.getValue(), zero);
}

TEST(NaturalTest, initWithVector) {
	auto a = natural({1,2,3,4});
	EXPECT_EQ(a.size(), 4);
}
TEST(NaturalTest, initWithNatural) {
	auto a = natural({6,5,4,3});
	natural b = natural(a);
	EXPECT_TRUE(a==b); //test operatora ==
}

TEST(NaturalTest, decremetZero) {
	std::vector<uint32_t> zero;
	zero.push_back(0);
	auto a = natural(zero);
	EXPECT_THROW(--a, std::runtime_error);
}
TEST(NaturalTest, divideByZero) {
	auto a = natural(0);
	auto b = natural({1266,16,7});
	natural c;
	EXPECT_THROW(c.divide(b,a), std::runtime_error);
}
TEST(NaturalTest, resultIsLessThanZero) {
	auto a = natural({2894,1});
	auto b = natural({1666,2});
	natural c;
	EXPECT_THROW(c.subtract(a,b), std::runtime_error);
}

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


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}