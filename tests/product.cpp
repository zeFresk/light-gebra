/* Tests Matrix product */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "smatrix.hpp"
#include "matrix_op.hpp"

#include <complex>

using namespace std::literals::complex_literals;

TEST(Initialization, scalar_product_inplace_float)
{
	SMatrix<float, 3, 3> matrix{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
	matrix *= 7.f;
	EXPECT_FLOAT_EQ(matrix(0, 0), 0.f);
	EXPECT_FLOAT_EQ(matrix(0, 1), 7.f);
}

TEST(Initialization, scalar_product_float)
{
	SMatrix<float, 3, 3> matrix{{0, 1, 2, 3, 4, 5, 6, 7, 8}};
	auto res = 7.f * matrix;
	EXPECT_FLOAT_EQ(res(0, 0), 0.f);
	EXPECT_FLOAT_EQ(res(0, 1), 7.f);
}

TEST(Initialization, scalar_product_symmetry)
{
	SMatrix<float, 3, 3> matrix{{0, 1, 2, 3, 4, 5, 6, 7, 8}};
	auto res1 = 7.f * matrix;
	auto res2 = matrix * 7.f;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			EXPECT_FLOAT_EQ(res1(i, j), res2(i, j));
}

TEST(Initialization, scalar_product_float_complex_inplace)
{
	using com_t = std::complex<float>;
	SMatrix<com_t, 3, 3> matrix{{0.f + 0.if, 1.f + 0.if, 2.f + 0.if},
		{0.f + 1.if, 1.f + 1.if, 2.f + 1.if},
		{0.f + 2.if, 1.f + 2.if, 2.f + 2.if}};
	matrix *= 7.f;
	EXPECT_FLOAT_EQ(matrix(0, 0).real(), 0.f);
	EXPECT_FLOAT_EQ(matrix(0, 0).imag(), 0.f);
	EXPECT_FLOAT_EQ(matrix(2, 2).real(), 2.f * 7.f);
	EXPECT_FLOAT_EQ(matrix(2, 2).imag(), 2.f * 7.f);
}

TEST(Initialization, scalar_product_float_complex)
{
	using com_t = std::complex<float>;
	SMatrix<com_t, 3, 3> matrix{{0.f + 0.if, 1.f + 0.if, 2.f + 0.if},
		{0.f + 1.if, 1.f + 1.if, 2.f + 1.if},
		{0.f + 2.if, 1.f + 2.if, 2.f + 2.if}};
	auto res = 7.f * matrix;
	EXPECT_FLOAT_EQ(res(0, 0).real(), 0.f);
	EXPECT_FLOAT_EQ(res(0, 0).imag(), 0.f);
	EXPECT_FLOAT_EQ(res(2, 2).real(), 2.f * 7.f);
	EXPECT_FLOAT_EQ(res(2, 2).imag(), 2.f * 7.f);
}
