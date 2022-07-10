#include "matrix/matrix.hpp"
#include "matrix/product.hpp"
#include "matrix/operations.hpp"
#include "maths/pow.hpp"

#include <benchmark/benchmark.h>

#include <random>

constexpr int until = 32;

template <typename Number, int n>
static void matrix_exponentiation(benchmark::State& state) {
	// init
	Matrix<Number, n, n> mat;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : mat)
		e = dis(gen);

	// benchmark
	const int max = until;
	for (auto _: state) {
		for (int i = 1; i < max; ++i)
		benchmark::DoNotOptimize(mat ^ i);
	}
	state.SetItemsProcessed(n*n * state.iterations() * max);
}

BENCHMARK(matrix_exponentiation<float, 2>);
BENCHMARK(matrix_exponentiation<float, 3>);
BENCHMARK(matrix_exponentiation<float, 4>);
BENCHMARK(matrix_exponentiation<float, 3>);
BENCHMARK(matrix_exponentiation<float, 5>);
BENCHMARK(matrix_exponentiation<float, 8>);
BENCHMARK(matrix_exponentiation<float, 16>);
BENCHMARK(matrix_exponentiation<float, 32>);
