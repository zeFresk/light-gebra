#include "matrix/matrix.hpp"
#include "matrix/kronecker.hpp"

#include <benchmark/benchmark.h>

#include <random>

template <typename Number, int m, int n, int p, int q>
static void kronecker_product(benchmark::State& state) {
	// init
	Matrix<Number, m, n> lhs;
	Matrix<Number, p, q> rhs;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : lhs)
		e = dis(gen);
	for (auto& e : rhs)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		benchmark::DoNotOptimize(kron(lhs, rhs));
	}
	state.SetItemsProcessed(m*p * q*n * state.iterations());
}

BENCHMARK(kronecker_product<float, 2, 2, 2, 2>);
BENCHMARK(kronecker_product<float, 2, 2, 4, 4>);
BENCHMARK(kronecker_product<float, 2, 2, 8, 8>);
BENCHMARK(kronecker_product<float, 3, 3, 3, 3>);
BENCHMARK(kronecker_product<float, 5, 5, 5, 5>);
BENCHMARK(kronecker_product<float, 8, 8, 8, 8>);
BENCHMARK(kronecker_product<float, 16, 16, 16, 16>);
