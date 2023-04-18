#include "rnd.h"

using namespace std;

namespace zloo
{
	rnd::rnd(const unsigned long long min, const unsigned long long max)
		:min_(min), max_(max)
	{
		random_device device;
		const mt19937_64 engine(device());
		engine_ = engine;
		const uniform_int_distribution<mt19937_64::result_type> distribution(min_, max_);
		distribution_ = distribution;
	}

	auto rnd::get_random(void) -> unsigned long long
	{
		return distribution_(engine_);
	}

	auto rnd::set_min(unsigned long long min) -> void
	{
		set_min_max(min, max_);
	}

	auto rnd::set_max(const unsigned long long max) -> void
	{
		set_min_max(min_, max);
	}

	auto rnd::set_min_max(const unsigned long long min, unsigned long long max) -> void
	{
		if (min > max) { max = min; }
		if (min_ != min) { min_ = min; }
		if (max_ != max) { max_ = max; }
		const uniform_int_distribution<std::mt19937_64::result_type> distribution(min_, max_);
		distribution_ = distribution;
	}
};