/* Tests Matrix kronecker product */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix.hpp"
#include "kronecker.hpp"

#include <complex>

using namespace std::literals::complex_literals;

TEST(MatrixKroneckerProduct, two_twobytwo) {
	Matrix<float, 2, 2> lhs{ { 1, 2 }, { 3, 4 } };
	Matrix<float, 2, 2> rhs{ { 0, 5 }, { 6, 7 } };
	Matrix<float, 4, 4> expected{ { 0, 5, 0, 10 }, { 6, 7, 12, 14 }, { 0, 15, 0, 20 }, { 18, 21, 24, 28 } };
	auto ret = kron(lhs, rhs);

	ASSERT_EQ(ret.lines(), expected.lines());
	ASSERT_EQ(ret.columns(), expected.columns());
	for (int i = 0; i < expected.lines(); ++i)
		for (int j = 0; j < expected.columns(); ++j)
			EXPECT_FLOAT_EQ(ret(i, j), expected(i, j));
}

TEST(MatrixKroneckerProduct, mixed_dimensions) {
	Matrix<int, 2, 3> lhs{ { 1, -4, 7 }, { -2, 3, 3 } };
	Matrix<int, 4, 4> rhs{ { 8, -9, -6, 5 }, { 1, -3, -4, 7 }, { 2, 8, -8, -3 }, { 1, 2, -5, -1 } };
	Matrix<int, 8, 12> expected{ { 8, -9, -6, 5, -32, 36, 24, -20, 56, -63, -42, 35 },
				     { 1, -3, -4, 7, -4, 12, 16, -28, 7, -21, -28, 49 },
				     { 2, 8, -8, -3, -8, -32, 32, 12, 14, 56, -56, -21 },
				     { 1, 2, -5, -1, -4, -8, 20, 4, 7, 14, -35, -7 },
				     { -16, 18, 12, -10, 24, -27, -18, 15, 24, -27, -18, 15 },
				     { -2, 6, 8, -14, 3, -9, -12, 21, 3, -9, -12, 21 },
				     { -4, -16, 16, 6, 6, 24, -24, -9, 6, 24, -24, -9 },
				     { -2, -4, 10, 2, 3, 6, -15, -3, 3, 6, -15, -3 } };
	auto ret = kron(lhs, rhs);

	ASSERT_EQ(ret.lines(), expected.lines());
	ASSERT_EQ(ret.columns(), expected.columns());
	for (int i = 0; i < expected.lines(); ++i)
		for (int j = 0; j < expected.columns(); ++j)
			EXPECT_EQ(ret(i, j), expected(i, j));
}
