/* Tests Matrix initialization */

#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "smatrix.hpp"

TEST(Initialization, small_float)
{
	SMatrix<float, 3, 3> matrix{{0, 1, 2, 3, 4, 5, 6, 7, 8}};
	EXPECT_EQ(matrix(0, 0), 0);
}

TEST(Initialization, big_float)
{
	SMatrix<float, 3, 3> matrix{{0, 1, 2, 3, 4, 5, 6, 7, 8}};
	EXPECT_EQ(matrix(0, 0), 0);
}
