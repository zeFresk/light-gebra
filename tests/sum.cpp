/* Tests Matrix sum */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix/matrix.hpp"
#include "matrix/sum.hpp"
#include "matrix/product.hpp"

TEST(MatrixSum, threebythree) {
	Matrix<float, 3, 3> lhs{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	Matrix<float, 3, 3> rhs{ { 9, 10, 11 }, { 12, 13, 14 }, { 15, 16, 17 } };
	Matrix<float, 3, 3> expected{ { 9, 11, 13 }, { 15, 17, 19 }, { 21, 23, 25 } };
	auto ret = lhs + rhs;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), expected(i, j));
}

TEST(MatrixSum, substraction_identity) {
	Matrix<float, 3, 3> lhs{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	Matrix<float, 3, 3> rhs{ { 9, 10, 11 }, { 12, 13, 14 }, { 15, 16, 17 } };
	auto expected = lhs + (-1 * rhs);
	auto ret = lhs - rhs;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), expected(i, j));
}
