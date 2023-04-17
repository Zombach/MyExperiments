#pragma once
#include <iostream>
#include <random>

class Random
{
public:
	explicit Random(const unsigned long long min = 0, const unsigned long long max = 100);

	auto get_random(void) -> unsigned long long;
	auto set_min(const unsigned long long min) -> void;
	auto set_max(const unsigned long long max) -> void;
	auto set_min_max(const unsigned long long min, unsigned long long max) -> void;

private:
	unsigned long long min_;
	unsigned long long max_;
	std::mt19937_64 engine_;
	std::uniform_int_distribution<std::mt19937_64::result_type> distribution_;
};