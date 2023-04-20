#include <iostream>
#include "Rnd.h"
#include <format>
#include <fstream>

#include "Dictionary.h"
#include "HashTables.h"
#include "LinkedNode.h"


using namespace std;
using namespace zloo;

int main()
{
	const auto node = new LinkedNode<int>(1);
	const auto node2 = new LinkedNode<int>(2);
	const auto node3 = new LinkedNode<int>(3);
    node->SetNode(node2);
    node2->SetNode(node3);
    node2->RemoveNode();
    node3->RemoveNode();
    node->RemoveNode();
    delete node;
    delete node2;
    delete node3;

    const auto hash = new HashTables();
    int code = hash->GetHash("world");


	const auto dict = new Dictionary<int, string>();
    bool is_add = dict->TryAdd(1, "fish");
    cout << is_add << endl;
    is_add = dict->TryAdd(1, "fish");
    cout << is_add << endl;
    is_add = dict->TryAdd(2, "fish");
    cout << is_add << endl;
    string value;
    bool is_get = dict->TryGetValue(1,  value);
    

    /*const string stringFormat;
    const auto Rnd = new random();
    unsigned long long digital = Rnd->GetRandom();
    cout << digital << endl;
    Rnd->SetMinMax(100, 1000);
    digital = Rnd->GetRandom();
    cout << digital << endl;*/
}