#include <maths/sqrt.hpp>

#include <benchmark/benchmark.h>

#include <random>
#include <array>

static void sqrt_small(benchmark::State& state) {
	//init
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(1.f, 4.f);
	auto x = dis(gen);

	// benchmark
	for (auto _: state) {
		benchmark::DoNotOptimize(sqrt(x));
	}
	state.SetItemsProcessed(state.iterations());
}

static void sqrt_orders(benchmark::State& state) {
	//init
	std::random_device rd;
	std::mt19937 gen(rd());

	constexpr int maxdigits = 20;
	std::array<float, maxdigits> arr;
	for (int i = 0; i < maxdigits; ++i) {
		std::uniform_real_distribution<float> dis(pow(10.f, i), pow(10.f, i+1));
		arr[i] = dis(gen);
	}

	// benchmark
	for (auto _: state) {
		for (auto x : arr)
		benchmark::DoNotOptimize(sqrt(x));
	}
	state.SetItemsProcessed(state.iterations() * arr.size());
}

BENCHMARK(sqrt_small);
BENCHMARK(sqrt_orders);
