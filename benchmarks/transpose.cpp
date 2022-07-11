#include "matrix/matrix.hpp"
#include "matrix/transpose.hpp"

#include <benchmark/benchmark.h>

#include <random>

template <typename Number, int n>
static void transpose(benchmark::State& state) {
	// init
	Matrix<Number, n, n> mat;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : mat)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		benchmark::DoNotOptimize(transpose(mat));
	}
	state.SetItemsProcessed(n*n * state.iterations());
}

BENCHMARK(transpose<float, 2>);
BENCHMARK(transpose<float, 32>);
BENCHMARK(transpose<float, 128>);
BENCHMARK(transpose<float, 512>);
