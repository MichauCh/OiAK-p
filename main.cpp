#include "sm.h"
#include <gtest/gtest.h>

TEST(SingMagnitudeTest, emptyNumber) {
	smNum a;
	EXPECT_FALSE(a.getSign());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}