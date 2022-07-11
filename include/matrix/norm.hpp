#ifndef LIGHTGEBRA_MATRIX_NORM_HPP
#define LIGHTGEBRA_MATRIX_NORM_HPP

#include "matrix/matrix.hpp"
#include "maths/abs.hpp"
#include "maths/sqrt.hpp"

template <typename Number, int n>
constexpr decltype(sqrt(std::declval<Number>())) norm(Matrix<Number, n, 1> const& vec) {
	Number ret{};
	for (int i = 0; i < n; ++i) {
		auto tmp = vec(i);
		ret += tmp*tmp;
	}
	return sqrt(ret);
}

template <typename Number, int n>
constexpr Number norm(Matrix<std::complex<Number>, n, 1> const& vec) {
	Number ret{};
	for (int i = 0; i < n; ++i) {
		auto re = std::real(vec(i));
		auto im = std::imag(vec(i));
		ret += re*re + im*im;
	}
	return sqrt(ret);
}

#endif
