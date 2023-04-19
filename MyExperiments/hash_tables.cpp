#include "hash_tables.h"

#include <iostream>

using namespace std;

namespace zloo
{
	hash_tables::hash_tables()
	{
		
	}
	
	auto hash_tables::get_hash(const string& key) -> int
	{
		int hash = 0;
		const int length = static_cast<int>(key.length());
		if (length > 0)
		{
			hash += length;
			for (int i = 0; i < length; i++)
			{
				hash += static_cast<unsigned char>(key[i]);
			}
		}
		return hash;
	}
};