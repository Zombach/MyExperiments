#include "Rnd.h"

using namespace std;

namespace zloo
{
	Rnd::Rnd(const unsigned long long min, const unsigned long long max)
		:min_(min), max_(max)
	{
		random_device device;
		const mt19937_64 engine(device());
		engine_ = engine;
		const uniform_int_distribution<mt19937_64::result_type> distribution(min_, max_);
		distribution_ = distribution;
	}

	auto Rnd::GetRandom(void) -> unsigned long long
	{
		return distribution_(engine_);
	}

	auto Rnd::SetMin(unsigned long long min) -> void
	{
		SetMinMax(min, max_);
	}

	auto Rnd::SetMax(const unsigned long long max) -> void
	{
		SetMinMax(min_, max);
	}

	auto Rnd::SetMinMax(const unsigned long long min, unsigned long long max) -> void
	{
		if (min > max) { max = min; }
		if (min_ != min) { min_ = min; }
		if (max_ != max) { max_ = max; }
		const uniform_int_distribution<std::mt19937_64::result_type> distribution(min_, max_);
		distribution_ = distribution;
	}
};