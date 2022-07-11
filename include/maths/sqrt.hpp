#ifndef LIGHTGEBRA_SQRT_HPP
#define LIGHTGEBRA_SQRT_HPP

#include <cassert>
#include <type_traits>

#include <maths/pow.hpp>
#include <maths/abs.hpp>

#include <iostream>

template <int precision = 4, typename Number = float>
constexpr Number sqrt(Number x) {
	using raw_t = std::remove_cv_t<std::remove_reference_t<Number>>;
	assert(x > raw_t{} && "Expected positive x");

	// reduce to [1, 4)
	int n = 0;
	while (x > raw_t{2.f}) {
		x /= raw_t{2.f};
		++n;
	}
	while (x < raw_t{1.f}) {
		x *= raw_t{2.f};
		--n;
	}
	int r = n % 2;
	n = (n - r) / 2;
	if (r)
		x *= 2;
	auto a = 1.f/3.f * x + 17.f/24.f;

	for (int i = 0; i < precision; ++i)
		a = a - ((a * a - x) / (raw_t{ 2.f } * a));
	/*for (int i = 0; i < abs(n)/2; ++i)
		a = a - ((a * a - x) / (raw_t{ 2.f } * a));*/


	if (n < 0) {
		a *= pow(raw_t{2.f}, n+r);
	} else if (n > 0) {
		a *= pow(raw_t{2.f}, n);
	}


	return a;
}

#endif
