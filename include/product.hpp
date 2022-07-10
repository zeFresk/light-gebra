#ifndef LIGHTGEBRA_MATRIX_PRODUCT_HPP
#define LIGHTGEBRA_MATRIX_PRODUCT_HPP

#include "matrix.hpp"

template <typename Number, int lin_lhs, int col, int col_rhs>
constexpr Matrix<Number, lin_lhs, col_rhs> operator*(Matrix<Number, lin_lhs, col> const& lhs,
						 Matrix<Number, col, col_rhs> const& rhs) {
	Matrix<Number, lin_lhs, col_rhs> ret;
	for (int i = 0; i < lin_lhs; ++i) {
		for (int j = 0; j < col_rhs; ++j) {
			ret(i, j) = Number{};
			for (int k = 0; k < col; ++k) {
				ret(i, j) += lhs(i, k) * rhs(k, j);
			}
		}
	}
	return ret;
}

template <typename K, typename Number, int lin, int col, typename = std::enable_if_t<std::is_convertible_v<decltype(std::declval<K>() * std::declval<Number>()), Number>>>
constexpr Matrix<Number, lin, col> operator*(Matrix<Number, lin, col> const& lhs, K&& val) {
	auto res = lhs;
	return res *= val;
}

template <typename K, typename Number, int lin, int col, typename = std::enable_if_t<std::is_convertible_v<decltype(std::declval<K>() * std::declval<Number>()), Number>>>
constexpr Matrix<Number, lin, col> operator*(K&& val, Matrix<Number, lin, col> const& lhs) {
	return lhs * val;
}

#endif
