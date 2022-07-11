/* Tests Matrix transposition */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix/matrix.hpp"
#include "matrix/transpose.hpp"

TEST(MatrixTransposition, square_matrix) {
	Matrix<float, 3, 3> lhs{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	auto ret = transpose(lhs);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), lhs(j, i));
}

TEST(MatrixTransposition, vvector) {
	Matrix<float, 3, 1> lhs{ 0, 1, 2 };
	auto ret = transpose(lhs);
	for (int i = 0; i < ret.lines(); ++i)
		for (int j = 0; j < ret.columns(); ++j)
			EXPECT_FLOAT_EQ(ret(i, j), lhs(j, i));
}

TEST(MatrixTransposition, hvector) {
	Matrix<float, 1, 3> lhs{ 0, 1, 2 };
	auto ret = transpose(lhs);
	for (int i = 0; i < ret.lines(); ++i)
		for (int j = 0; j < ret.columns(); ++j)
			EXPECT_FLOAT_EQ(ret(i, j), lhs(j, i));
}
