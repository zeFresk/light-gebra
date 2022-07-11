#ifndef LIGHTGEBRA_ABS_HPP
#define LIGHTGEBRA_ABS_HPP

#include <type_traits>
#include <complex>

template <typename T>
constexpr std::remove_reference_t<std::remove_cv_t<T>> abs(T&& x) {
	return x > std::remove_reference_t<std::remove_cv_t<T>>{} ? x : -x;
}

#endif
