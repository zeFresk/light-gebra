#include "matrix/matrix.hpp"
#include "matrix/qr.hpp"

#include <benchmark/benchmark.h>

#include <random>

template <typename Number, int n>
static void qr_decomposition(benchmark::State& state) {
	// init
	Matrix<Number, n, n> A;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 10.f);
	for (auto& e : A)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		benchmark::DoNotOptimize(qr(A));
	}
	state.SetItemsProcessed(2*n*n * state.iterations());
}

BENCHMARK(qr_decomposition<float, 2>);
BENCHMARK(qr_decomposition<float, 3>);
BENCHMARK(qr_decomposition<float, 4>);
BENCHMARK(qr_decomposition<float, 8>);
BENCHMARK(qr_decomposition<float, 16>);
BENCHMARK(qr_decomposition<float, 64>);
BENCHMARK(qr_decomposition<float, 128>);
BENCHMARK(qr_decomposition<float, 256>);
