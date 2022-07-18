#ifndef LIGHTGEBRA_POW_HPP
#define LIGHTGEBRA_POW_HPP

#include <type_traits>
#include <cassert>

template <typename T, typename = std::enable_if_t<std::is_convertible_v<float, std::remove_reference_t<std::remove_cv_t<T>>>>>
constexpr std::remove_reference_t<std::remove_cv_t<T>> pow(T&& v, int n) {
	if (n == 0)
		return std::remove_reference_t<std::remove_cv_t<T>>{static_cast<std::remove_reference_t<std::remove_cv_t<T>>>(1.f)};
	if (n < 0)
		return std::remove_reference_t<std::remove_cv_t<T>>{static_cast<std::remove_reference_t<std::remove_cv_t<T>>>(1.f)} / pow(v, -n);
	return (n % 2 == 0) ? pow(v * v, n / 2) : v * pow(v * v, (n-1)/2);
}

template <typename T>
constexpr typename std::enable_if_t<!std::is_convertible_v<float, std::remove_reference_t<std::remove_cv_t<T>>>, std::remove_reference_t<std::remove_cv_t<T>>> pow(T&& v, int n) {
	assert(n > 0 && "Bad power");
	if (n == 1)
		return v;
	return (n % 2 == 0) ? pow(v * v, n / 2) : v * pow(v * v, (n-1)/2);
}

#endif
