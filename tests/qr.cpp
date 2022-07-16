/* Tests Matrix QR decomposition */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include <matrix/matrix.hpp>
#include <matrix/initializers.hpp>
#include "matrix/qr.hpp"
#include "matrix/product.hpp"

constexpr auto epsilon = 5e-5;

TEST(MatrixQR, qr_threeby_three) {
	// from wikipedia
	Matrix<float, 3, 3> A{ { 12.f, -51.f, 4.f }, { 6.f, 167.f, -68.f }, { -4.f, 24.f, -41.f } };
	auto ret = qr(A);
	auto q = ret.first;
	auto r = ret.second;

	Matrix<float, 3, 3> qexp{ { 6.f / 7.f, -69.f / 175.f, 58.f / 175.f },
				  { 3.f / 7.f, 158.f / 175.f, -6.f / 175.f },
				  { -2.f / 7.f, 6.f / 35.f, 33.f / 35.f } };
	Matrix<float, 3, 3> rexp{ { 14.f, 21.f, -14.f }, { 0.f, 175.f, -70.f }, { 0.f, 0.f, -35.f } };

	auto prod = q * r;

	// test
	EXPECT_EQ(q.lines(), qexp.lines());
	EXPECT_EQ(q.columns(), qexp.columns());
	EXPECT_EQ(r.lines(), rexp.lines());
	EXPECT_EQ(r.columns(), rexp.columns());
	for (int l = 0; l < q.lines(); ++l) {
		for (int c = 0; c < q.columns(); ++c) {
			EXPECT_NEAR(q(l, c), qexp(l, c), epsilon);
			EXPECT_NEAR(r(l, c), rexp(l, c), epsilon);
			EXPECT_NEAR(prod(l, c), A(l, c), epsilon);
		}
	}
}
