#ifndef LIGHTGEBRA_MATRIX_QR_HPP
#define LIGHTGEBRA_MATRIX_QR_HPP

#include "matrix/matrix.hpp"
#include "matrix/product.hpp"
#include "matrix/sum.hpp"
#include "matrix/norm.hpp"
#include "matrix/initializers.hpp"
#include "matrix/transpose.hpp"

#include <functional>
#include <cassert>

template <typename Number, int lin, int col>
constexpr Matrix<Number, lin, 1> column(Matrix<Number, lin, col> const& mat, int column) {
	Matrix<Number, lin, 1> ret;
	for (int i = 0; i < mat.lines(); ++i)
		ret(i) = mat(i, column);
	return ret;
}

template <typename Number>
constexpr bool positive(Number n) {
	return n >= Number{};
}

/* Householder reflection */

template <typename Number, int lin, int col, typename = std::enable_if_t<lin == col && col != 1>>
constexpr std::pair<Matrix<Number, lin, col>, Matrix<Number, lin, col>> qr(Matrix<Number, lin, col> mat) {
	Matrix<Number, lin, col> q;
	for (int c = 0; c < mat.columns()-1; ++c) {
		auto x = column(mat, c); // column vector
		for (int i = 0; i < c; ++i)
			x(i) = Number{};
		auto sign = positive(x(0));
		auto alpha = norm(x);
		/*if (sign)
			alpha *= Number{ -1 };*/
		decltype(x) e1{};
		e1(c) = Number{ 1 };
		auto tmp = alpha * e1;
		auto u = x - tmp;
		auto v = u / norm(u);
		auto id = identity<Number, lin>();
		auto vv = v * transpose(v);
		auto qc = id - Number{ 2 } * vv;
		if (c == 0) {
			q = qc;
		} else {
			q = q * qc;
		}
		mat = qc * mat;
	}
	return { q, mat };
}

#endif
