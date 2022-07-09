/* Tests Matrix product */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "smatrix.hpp"
#include "matrix_op.hpp"
#include "initializers.hpp"

#include <complex>

using namespace std::literals::complex_literals;

TEST(MatrixProduct, square_product_3by3_squared) {
	SMatrix<float, 3, 3> matrix{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	SMatrix<float, 3, 3> expected{ { 15, 18, 21 }, { 42, 54, 66 }, { 69, 90, 111 } };
	auto ret = matrix * matrix;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), expected(i, j));
}

TEST(MatrixProduct, square_product_3by3_identityright) {
	SMatrix<float, 3, 3> matrix{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	auto id = identity<float, 3>();
	auto ret = matrix * id;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), matrix(i, j));
}

TEST(MatrixProduct, square_product_3by3_identityleft) {
	SMatrix<float, 3, 3> matrix{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	auto id = identity<float, 3>();
	auto ret = id * matrix;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), matrix(i, j));
}

TEST(MatrixProduct, square_product_3by3) {
	SMatrix<float, 3, 3> lhs{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	SMatrix<float, 3, 3> rhs{ { 9, 10, 11 }, { 12, 13, 14 }, { 15, 16, 17 } };
	SMatrix<float, 3, 3> expected{ { 42, 45, 48 }, { 150, 162, 174 }, { 258, 279, 300 } };
	auto ret = lhs * rhs;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), expected(i, j));
}

TEST(MatrixProduct, linevec_times_colvec_into_scalar) {
	SMatrix<float, 1, 3> lhs{ 0, 1, 2 };
	SMatrix<float, 3, 1> rhs{ 3, 4, 5 };
	float expected = 14.f;
	float ret = lhs * rhs;
	EXPECT_FLOAT_EQ(ret, expected);
}

TEST(MatrixProduct, three_two_times_two_three) {
	SMatrix<float, 2, 3> lhs{ { 0, 1, 2 }, { 3, 4, 5 } };
	SMatrix<float, 3, 2> rhs{ { 6, 7 }, { 8, 9 }, { 10, 11 } };
	Matrix<float, 2, 2> expected{ { 28, 31 }, { 100, 112 } };
	auto ret = lhs * rhs;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			EXPECT_FLOAT_EQ(ret(i, j), expected(i, j));
}
