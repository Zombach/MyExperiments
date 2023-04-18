#pragma once
#include <map>

namespace zloo
{
	template<typename T, typename U>
	class dictionary
	{
	public:
		dictionary();
		~dictionary();

		auto try_add(T key, U value) -> bool;
		auto try_get_value(T key, U& value) -> bool;
	private:
		std::map<T, U> *dictionary_;
	};


	template <typename T, typename U>
	dictionary<T, U>::dictionary()
	{
		dictionary_ = new std::map<T, U>();
	}

	template <typename T, typename U>
	dictionary<T, U>::~dictionary()
	{
	}

	template <typename T, typename U>
	auto dictionary<T, U>::try_add(T key, U value) -> bool
	{
		bool is_done = false;
		if (!dictionary_->contains(key))
		{
			dictionary_->insert(std::make_pair(key, value));
			is_done = true;
		}
		return is_done;
	}

	template <typename T, typename U>
	auto dictionary<T, U>::try_get_value(T key, U& value) -> bool
	{
		bool is_done = false;
		if(dictionary_->contains(key))
		{ 
			value = dictionary_->at(key);
			is_done = true;
		}
		return is_done;
	}
};