/* Tests constexpr sqrt */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "maths/sqrt.hpp"
#include <cmath>
#include <algorithm>

TEST(MathsSqrt, root2) {
	constexpr auto root2 = sqrt<7>(2.f);
	constexpr float epsilon = 1e-6;
	EXPECT_NEAR(root2, std::sqrt(2.f), epsilon);
}

TEST(MathsSqrt, sup_one) {
	constexpr int maxdigits = 10;
	constexpr float epsilon = 0.001;
	float base = 2.f;
	for (int i = 0; i < maxdigits; ++i, base *= 10.f) {
		auto ret = sqrt<7>(base);
		auto expected = std::sqrt(base);
		EXPECT_NEAR(ret, expected, epsilon * std::max(ret, expected));
	}
}

TEST(MathsSqrt, inf_one) {
	constexpr int maxdigits = 5;
	constexpr float epsilon = 0.001;
	float base = .2f;
	for (int i = 0; i < maxdigits; ++i, base /= 10.f) {
		auto ret = sqrt<7>(base);
		auto expected = std::sqrt(base);
		EXPECT_NEAR(ret, expected, epsilon * std::max(ret, expected));
	}
}
