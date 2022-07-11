#include "matrix/matrix.hpp"

#include <benchmark/benchmark.h>

#include <random>

template <typename Number, int n>
static void access_doublefor_lf(benchmark::State& state) {
	// init
	Matrix<Number, n, n> mat;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : mat)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		for (int i = 0; i < mat.lines(); ++i)
			for (int j = 0; j < mat.columns(); ++j)
				benchmark::DoNotOptimize(mat(i,j));
	}
	state.SetItemsProcessed(n*n * state.iterations());
}

BENCHMARK(access_doublefor_lf<float, 2>);
BENCHMARK(access_doublefor_lf<float, 32>);
BENCHMARK(access_doublefor_lf<float, 128>);
BENCHMARK(access_doublefor_lf<float, 512>);

template <typename Number, int n>
static void access_doublefor_cf(benchmark::State& state) {
	// init
	Matrix<Number, n, n> mat;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : mat)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		for (int i = 0; i < mat.columns(); ++i)
			for (int j = 0; j < mat.lines(); ++j)
				benchmark::DoNotOptimize(mat(j,i));
	}
	state.SetItemsProcessed(n*n * state.iterations());
}

BENCHMARK(access_doublefor_cf<float, 2>);
BENCHMARK(access_doublefor_cf<float, 32>);
BENCHMARK(access_doublefor_cf<float, 128>);
BENCHMARK(access_doublefor_cf<float, 512>);

template <typename Number, int n>
static void access_foreach(benchmark::State& state) {
	// init
	Matrix<Number, n, n> mat;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(-1.f, 1.f);
	for (auto& e : mat)
		e = dis(gen);

	// benchmark
	for (auto _: state) {
		for (auto const& e : mat)
			benchmark::DoNotOptimize(e);
	}
	state.SetItemsProcessed(n*n * state.iterations());
}

BENCHMARK(access_foreach<float, 2>);
BENCHMARK(access_foreach<float, 32>);
BENCHMARK(access_foreach<float, 128>);
BENCHMARK(access_foreach<float, 512>);
