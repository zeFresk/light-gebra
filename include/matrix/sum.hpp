#ifndef LIGHTGEBRA_MATRIX_SUM_HPP
#define LIGHTGEBRA_MATRIX_SUM_HPP

#include "matrix/matrix.hpp"

template <typename Number, int lin, int col>
constexpr Matrix<Number, lin, col> operator+(Matrix<Number, lin, col> const& lhs, Matrix<Number, lin, col> const& rhs) {
	Matrix<Number, lin, col> ret{lhs};
	ret += rhs;
	return ret;
}

#endif
