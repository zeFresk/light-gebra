/* Tests Matrix constexpr functionnalities */

/* Tests Matrix kronecker product */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix/matrix.hpp"
#include <matrix/product.hpp>
#include "matrix/kronecker.hpp"
#include "maths/sqrt.hpp"

#include <complex>
#include <cmath>

using namespace std::literals::complex_literals;
using Gate = Matrix<float, 2, 2>;

TEST(Constexpr, basic_init) {
	static constexpr Gate ug_i{ 1.f, 0.f, 0.f, 1.f };
	EXPECT_EQ(ug_i(0, 0), 1.f);
}

TEST(Constexpr, root) {
	static constexpr float root2 = sqrt<7>(2.f);
	EXPECT_FLOAT_EQ(root2, std::sqrt(2.f));
}

TEST(Constexpr, prod_init_multisteps) {
	static constexpr float inv_root2 = 1.f/sqrt<7>(2.f);
	static constexpr Gate ug_h{ 1.f, 1.f, 1.f, -1.f };
	static constexpr auto normalized_h = ug_h * inv_root2;
	EXPECT_FLOAT_EQ(normalized_h(0, 0) * sqrt<7>(2.f), 1.f);
}

TEST(Constexpr, prod_init_onestep) {
	static constexpr Gate ug_h = Gate{ 1.f, 1.f, 1.f, -1.f } * (1.f/sqrt<7>(2.f));
	EXPECT_FLOAT_EQ(ug_h(0, 0) * sqrt<7>(2.f), 1.f);
}

TEST(Constexpr, kronecker) {
	static constexpr Gate ug_i{ 1.f, 0.f, 0.f, 1.f };
	static constexpr Gate ug_x{0.f, 1.f, 1.f, 0.f};
	static constexpr auto res = kron(ug_i, ug_x);
	EXPECT_EQ(ug_i(0, 0), 1.f);
}
