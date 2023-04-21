#pragma once
#include <string>

namespace zloo
{
	template<typename T>
	class Hash
	{
	public:
		Hash();

		auto GetHash(T& key) -> int;
	};

	template<typename T>
	inline Hash<T>::Hash()
	{
	}

	template<typename T>
	inline auto Hash<T>::GetHash(T& key) -> int
	{
		if (typeid(key) == typeid(std::string))
		{
			auto value = static_cast<std::string>(key);
			return value.length();
		}
		return sizeof(key);
	}
};