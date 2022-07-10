#include "matrix.hpp"
#include "product.hpp"

#include <benchmark/benchmark.h>

#include <random>

template <typename Number, int n>
static void scalar_matrix_multiplication(benchmark::State& state) {
	// init
	Matrix<Number, n, n> lhs;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	auto x = dis(gen);
	for (auto& e : lhs)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		benchmark::DoNotOptimize(x * lhs);
	}
	state.SetItemsProcessed(n*n * state.iterations());
}

BENCHMARK(scalar_matrix_multiplication<float, 3>);
BENCHMARK(scalar_matrix_multiplication<float, 5>);
BENCHMARK(scalar_matrix_multiplication<float, 9>);
BENCHMARK(scalar_matrix_multiplication<float, 16>);
BENCHMARK(scalar_matrix_multiplication<float, 32>);
BENCHMARK(scalar_matrix_multiplication<float, 64>);
BENCHMARK(scalar_matrix_multiplication<float, 128>);
BENCHMARK(scalar_matrix_multiplication<float, 256>);
BENCHMARK(scalar_matrix_multiplication<float, 512>);
