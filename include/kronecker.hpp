#ifndef LIGHTGEBRA_MATRIX_KRONECKER_HPP
#define LIGHTGEBRA_MATRIX_KRONECKER_HPP

#include "matrix.hpp"

template <typename NumberLeft, typename NumberRight, int m, int n, int p, int q>
constexpr Matrix<decltype(std::declval<NumberLeft>() * std::declval<NumberRight>()), p * m, q * n>
kron(Matrix<NumberLeft, m, n> const& lhs, Matrix<NumberRight, p, q> const& rhs) {
	Matrix<decltype(std::declval<NumberLeft>() * std::declval<NumberRight>()), p * m, q * n> ret;
	for (int i = 0; i < m*p; ++i) {
		for (int j = 0; j < q*n; ++j) {
			ret(i, j) = lhs(i / p, j / q) * rhs(i % p, j % q);
		}
	}
	return ret;
}

#endif
