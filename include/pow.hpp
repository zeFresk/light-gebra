#ifndef LIGHTGEBRA_POW_HPP
#define LIGHTGEBRA_POW_HPP

#include <type_traits>
#include <cassert>

template <typename T>
constexpr std::remove_reference_t<std::remove_cv_t<T>> pow(T&& v, int n) {
	assert(n > 0 && "Bad power");
	if (n == 1)
		return v;
	return (n % 2 == 0) ? pow(v * v, n / 2) : v * pow(v * v, (n-1)/2);
}

#include "matrix.hpp"

template <typename Number, int n>
constexpr Matrix<Number, n, n> operator^(Matrix<Number, n, n> const& m, int p) {
	return pow(m, p);
}
#endif
