#include <iostream>
#include "rnd.h"
#include <format>
#include <fstream>

#include "dictionary.h"
#include "hash_tables.h"
#include "linked_node.h"


using namespace std;
using namespace zloo;

int main()
{
	const auto node = new linked_node<int>(1);
	const auto node2 = new linked_node<int>(2);
	const auto node3 = new linked_node<int>(3);
    node->set_node(node2);
    node2->set_node(node3);
    node2->remove_node();
    node3->remove_node();
    node->remove_node();
    delete node;
    delete node2;
    delete node3;

    const auto hash = new hash_tables();
    int code = hash->get_hash("world");


	const auto dict = new dictionary<int, string>();
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