#include "HashTables.h"

#include <iostream>

using namespace std;

namespace zloo
{
	HashTables::HashTables()
	{
		
	}
	
	auto HashTables::GetHash(const string& key) -> int
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