#pragma once
#include <map>

template<class T, class U>
class dictionary
{
public:
	dictionary();
	~dictionary();
private:
	std::map<T, U> dictionary_;
};