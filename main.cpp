#include "sm.h"
#include <gtest/gtest.h>

/*Testy wybranych metod klasy Natural*/
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

/*Testy operacji arytmetycznych na Natural*/
TEST(NaturalAddTest, natAdd1) {
	auto a = natural({ 17,22,11 });
	auto b = natural({ 12,11,10 });
	auto c = natural({ 29,33,21 });
	natural wynik;
	wynik.add(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());

};

TEST(NaturalSubTest, natSub1) {
	auto a = natural({ 17,22,11 });
	auto b = natural({ 12,11,10 });
	auto c = natural({ 5,11,1 });
	natural wynik;
	wynik.subtract(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());

};
TEST(NaturalDivTest, natDiv1) {
	auto a = natural({ 17,22,11 });
	auto b = natural({ 12,11,10 });
	auto c = natural({ 1 });
	natural wynik;
	wynik.divide(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());

};

TEST(NaturalMulTest, natMul1) {
	auto a = natural({ 10, 11 , 789 });
	auto b = natural({ 192,62,55826 });
	auto c = natural({ 1920, 2732, 710430, 663004, 44046714 });
	natural wynik;
	wynik.multiply(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());
}

/*Testy wybranych metod klasy smNum*/
TEST(SingMagnitudeTest, initWithZero) {
	std::vector<uint32_t> zero;
	uint32_t initiator = 0;
	zero.push_back(0);
	auto a = smNum(initiator);
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

/*Testy operacji arytmetycznych na smNum*/
//dodawanie znaki +
TEST(smNumAddTest, smNumAdd1) {
	auto a = natural({ 82931, 2136512, 12376 });
	auto b = natural({ 192,62 });
	auto c = natural({ 83123, 2136574, 12376 });
	auto  a1 = smNum({ 0,a });
	auto  b1 = smNum({ 0,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.add(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
//dodawanie znaki -
TEST(smNumAddTest, smNumAdd2) {
	auto a = natural({ 27623,9152, 9124 });
	auto b = natural({  1192, 1925});
	auto c = natural({ 83123, 2136574, 12376 });
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 1,c });
	smNum wynik;
	wynik.add(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}