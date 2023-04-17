#include <iostream>
#include "Random.h"
#include <format>

using namespace std;

int main()
{
    const string stringFormat;
    auto random = new Random();
    unsigned long long digital = random->get_random();
    random->set_min_max(100, 1000);
    string result = format(stringFormat, digital);
    digital = random->get_random();
    string result2 = format(stringFormat, digital);
    cout << result << endl << result2;
}