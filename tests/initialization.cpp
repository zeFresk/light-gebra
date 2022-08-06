/* Tests Matrix initialization */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix/matrix.hpp"
#include "matrix/initializers.hpp"

#include <complex>

using namespace std::literals::complex_literals;

TEST(Initialization, small_float) {
	Matrix<float, 3, 3> matrix{ { 0, 1, 2, 3, 4, 5, 6, 7, 8 } };
	EXPECT_EQ(matrix(0, 0), 0);
}

TEST(Initialization, small_float_intuitive) {
	Matrix<float, 3, 3> matrix{ { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	EXPECT_EQ(matrix(0, 0), 0);
	EXPECT_EQ(matrix(0, 2), 2);
	EXPECT_EQ(matrix(1, 0), 3);
	EXPECT_EQ(matrix(2, 0), 6);
	EXPECT_EQ(matrix(2, 2), 8);
}

TEST(Initialization, small_double) {
	Matrix<double, 3, 3> matrix{ { 0, 1, 2, 3, 4, 5, 6, 7, 8 } };
	EXPECT_EQ(matrix(0, 0), 0);
}

TEST(Initialization, small_complex) {
	using com_t = std::complex<float>;
	Matrix<com_t, 3, 3> matrix;
	matrix(0, 0) = 0.f + 1.if;
	EXPECT_EQ(matrix(0, 0), 0.f + 1.if);
}

TEST(Initialization, identity_float_small) {
	constexpr int size = 3;
	auto id = identity<float, size>();
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			EXPECT_FLOAT_EQ(id(i, j), (i == j) ? 1.f : 0.f);
}

TEST(Initialization, identity_float_big) {
	constexpr int size = 512;
	auto id = identity<float, size>();
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			EXPECT_FLOAT_EQ(id(i, j), (i == j) ? 1.f : 0.f);
}

TEST(Initialization, identity_complex) {
	constexpr int size = 8;
	auto id = identity<std::complex<float>, size>();
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			EXPECT_EQ(id(i, j), (i == j) ? 1.f : 0.f);
}
