#include "matrix.hpp"
#include "sum.hpp"

#include <benchmark/benchmark.h>

#include <random>

template <typename Number, int n>
static void square_matrix_sum(benchmark::State& state) {
	// init
	Matrix<Number, n, n> lhs, rhs;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : lhs)
		e = dis(gen);
	for (auto& e : rhs)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		benchmark::DoNotOptimize(lhs + rhs);
	}
	state.SetItemsProcessed(n*n * state.iterations());
}

BENCHMARK(square_matrix_sum<float, 3>);
BENCHMARK(square_matrix_sum<float, 5>);
BENCHMARK(square_matrix_sum<float, 9>);
BENCHMARK(square_matrix_sum<float, 16>);
BENCHMARK(square_matrix_sum<float, 32>);
BENCHMARK(square_matrix_sum<float, 64>);
BENCHMARK(square_matrix_sum<float, 128>);
BENCHMARK(square_matrix_sum<float, 256>);
BENCHMARK(square_matrix_sum<float, 512>);
