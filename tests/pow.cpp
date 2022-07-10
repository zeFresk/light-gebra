/* Tests Matrix power */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix.hpp"
#include "product.hpp"
#include "pow.hpp"

TEST(MatrixPower, increasing_powers) {
	Matrix<float, 2, 2> lhs{ { 1, 2 }, { 3, 4 } };

	auto cur = lhs;
	constexpr int max = 32;
	for (int i = 1; i < max; ++i) {
		auto ret = lhs ^ i;
		for (int i = 0; i < cur.lines(); ++i)
			for (int j = 0; j < cur.columns(); ++j)
				EXPECT_FLOAT_EQ(cur(i, j), ret(i, j));
		cur = cur * lhs;
	}
}
