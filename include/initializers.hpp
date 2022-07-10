#ifndef LIGHTGEBRA_INITIALIZERS_HPP
#define LIGHTGEBRA_INITIALIZERS_HPP

#include <matrix.hpp>

template <typename Number, int lin, int col>
constexpr void eye(Matrix<Number, lin, col>& mat) {
	for (int i = 0; i < lin; ++i)
		for (int j = 0; j < col; ++j)
			mat(i, j) = Number{static_cast<int>(i == j)};
}

template <typename Number, int n>
constexpr Matrix<Number, n, n> identity() {
	Matrix<Number, n, n> ret;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret(i, j) = Number{static_cast<int>(i == j)};
	return ret;
}

#endif
