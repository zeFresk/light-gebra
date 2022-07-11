#ifndef LIGHTGEBRA_MATRIX_TRANSPOSE_HPP
#define LIGHTGEBRA_MATRIX_TRANSPOSE_HPP

#include "matrix/matrix.hpp"

template <typename Number, int l, int c>
constexpr Matrix<Number, c, l> transpose(Matrix<Number, l, c> const& mat) {
	Matrix<Number, c, l> ret;
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < c; ++j)
			ret(j, i) = mat(i, j);

	return ret;
}

#endif
