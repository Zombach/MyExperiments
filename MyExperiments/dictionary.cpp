#include "dictionary.h"
using namespace std;

template <class T, class U>
dictionary<T, U>::dictionary()
{
	dictionary_ = new map<T, U>();
}

template <class T, class U>
dictionary<T, U>::~dictionary()
{
}
