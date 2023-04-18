#include <iostream>
#include "rnd.h"
#include <format>

#include "dictionary.h"


using namespace std;

int main()
{
	auto* dict = new zloo::dictionary<int, string>();

    bool is_add = dict->try_add(1, "fish");
    cout << is_add << endl;
    is_add = dict->try_add(1, "fish");
    cout << is_add << endl;
    is_add = dict->try_add(2, "fish");
    cout << is_add << endl;
    string value;
    bool is_get = dict->try_get_value(1,  value);
    

    /*const string stringFormat;
    const auto rnd = new random();
    unsigned long long digital = rnd->get_random();
    cout << digital << endl;
    rnd->set_min_max(100, 1000);
    digital = rnd->get_random();
    cout << digital << endl;*/
}