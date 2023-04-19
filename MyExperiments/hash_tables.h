#pragma once
#include <string>

#include "dictionary.h"
#include "linked_node.h"

namespace zloo
{
	class hash_tables
	{
	public:
		hash_tables();

		auto get_hash(const std::string& key) -> int;
	private:
		dictionary<int, linked_node<std::string>> dictionary_;
	};
};