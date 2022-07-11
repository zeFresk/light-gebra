/* Tests Vector norm */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "matrix/matrix.hpp"
#include "matrix/norm.hpp"

#include <complex>

TEST(MatrixTransposition, real_vector_small) {
	Matrix<float, 2, 1> lhs{ 3, 4 };
	auto ret = norm(lhs);
	EXPECT_FLOAT_EQ(ret, sqrt(3.f*3.f + 4.f*4.f));
}

TEST(MatrixTransposition, real_vector_big) {
	Matrix<float, 25, 1> lhs;
	float expected = 0.f;
	for (int i = 0; i < lhs.lines(); ++i) {
		lhs(i) = i;
		expected += i * i;
	}
	auto ret = norm(lhs);
	EXPECT_FLOAT_EQ(ret, sqrt(expected));
}


TEST(MatrixTransposition, complex_vector) {
	using namespace std::complex_literals;
	Matrix<std::complex<float>, 2, 1> lhs{ 1.f + 7.if, 2.f - 6.if };
	auto ret = norm(lhs);
	EXPECT_FLOAT_EQ(ret, sqrt(90.f));
}
