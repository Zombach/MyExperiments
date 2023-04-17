#include <iostream>
#include "random.h"
#include <format>

using namespace std;

int main()
{
    const string stringFormat;
    const auto rnd = new random();
    unsigned long long digital = rnd->get_random();
    cout << digital << endl;
    rnd->set_min_max(100, 1000);
    digital = rnd->get_random();
    cout << digital << endl;
 }