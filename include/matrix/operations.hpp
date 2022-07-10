#ifndef LIGHTGEBRA_MATRIX_OPERATIONS_HPP
#define LIGHTGEBRA_MATRIX_OPERATIONS_HPP

#include "matrix.hpp"
#include "product.hpp"
#include "sum.hpp"
#include "maths/pow.hpp"

template <typename Number, int n>
constexpr Matrix<Number, n, n> operator^(Matrix<Number, n, n> const& m, int p) {
	return pow(m, p);
}

#endif
