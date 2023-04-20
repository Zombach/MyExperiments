#pragma once
#include <map>

namespace zloo
{
	template<typename T, typename U>
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		auto TryAdd(T key, U value) -> bool;
		auto TryGetValue(T key, U& value) -> bool;
	private:
		std::map<T, U> *dictionary_;
	};


	template <typename T, typename U>
	Dictionary<T, U>::Dictionary()
	{
		dictionary_ = new std::map<T, U>();
	}

	template <typename T, typename U>
	Dictionary<T, U>::~Dictionary()
	{
	}

	template <typename T, typename U>
	auto Dictionary<T, U>::TryAdd(T key, U value) -> bool
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
	auto Dictionary<T, U>::TryGetValue(T key, U& value) -> bool
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