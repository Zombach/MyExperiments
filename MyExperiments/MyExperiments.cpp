#include <iostream>
#include "random.h"
#include <format>

#include "dictionary.h"


using namespace std;

int main()
{
	auto* dict = new zloo::dictionary<int, string>();
    dict->try_add(1, "fish");
    

    /*const string stringFormat;
    const auto rnd = new random();
    unsigned long long digital = rnd->get_random();
    cout << digital << endl;
    rnd->set_min_max(100, 1000);
    digital = rnd->get_random();
    cout << digital << endl;*/
}