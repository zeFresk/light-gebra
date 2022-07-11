/* Tests constexpr sqrt */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "maths/sqrt.hpp"
#include <cmath>

TEST(MathsSqrt, root2) {
	constexpr auto root2 = sqrt<7>(2.f);
	constexpr float epsilon = 1e-6;
	EXPECT_NEAR(root2, sqrt(2.f), epsilon);
}

TEST(MathsSqrt, orders) {
	constexpr int maxdigits = 20;
	constexpr float epsilon = 1e-6;
	float base = 0.00002f;
	for (int i = 0; i < maxdigits; ++i, base *= 10.f) {
		auto ret = sqrt<10>(base);
		auto expected = sqrt(base);
		EXPECT_NEAR(ret, expected, epsilon);
	}
}
