#pragma once
#include <random>

namespace zloo
{
	class Rnd
	{
	public:
		explicit Rnd(const unsigned long long min = 0, const unsigned long long max = 100);

		auto GetRandom(void) -> unsigned long long;
		auto SetMin(unsigned long long min) -> void;
		auto SetMax(unsigned long long max) -> void;
		auto SetMinMax(unsigned long long min, unsigned long long max) -> void;

	private:
		unsigned long long min_;
		unsigned long long max_;
		std::mt19937_64 engine_;
		std::uniform_int_distribution<std::mt19937_64::result_type> distribution_;
	};
};