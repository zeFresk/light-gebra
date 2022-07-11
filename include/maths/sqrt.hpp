#ifndef LIGHTGEBRA_SQRT_HPP
#define LIGHTGEBRA_SQRT_HPP

#include <cassert>
#include <type_traits>

#include <maths/pow.hpp>
#include <maths/abs.hpp>

template <int precision = 7, typename Number = float>
constexpr std::remove_cv_t<std::remove_reference_t<Number>> sqrt(Number&& x) {
	using raw_t = std::remove_cv_t<std::remove_reference_t<Number>>;
	assert(x > raw_t{} && "Expected positive x");

	raw_t a = x;
	// reduce to [1, 4)
	int n = 0;
	while (a > raw_t{4.f}) {
		a /= raw_t{2.f};
		++n;
	}
	while (a < raw_t{1.f}) {
		a *= raw_t{2.f};
		--n;
	}

	for (int i = 0; i < precision; ++i)
		a = a - ((a * a - x) / (raw_t{ 2.f } * a));
	for (int i = 0; i < abs(n)/2; ++i)
		a = a - ((a * a - x) / (raw_t{ 2.f } * a));


	if (n != 0) {
		a *= pow(raw_t{2.f}, n);
	}

	return a;
}

#endif
