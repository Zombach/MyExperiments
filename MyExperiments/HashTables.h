#pragma once
#include <string>

#include "Dictionary.h"
#include "LinkedNode.h"

namespace zloo
{
	class HashTables
	{
	public:
		HashTables();

		auto GetHash(const std::string& key) -> int;
	private:
		Dictionary<int, LinkedNode<std::string>> dictionary_;
	};
};