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
    auto node = new LinkedNode<int>(1);
    auto node2 = new LinkedNode<int>(2);
    auto node3 = new LinkedNode<int>(3);
    auto node4 = new LinkedNode<int>(4);
    node->AddNode(node2);
    node2->AddNode(node3);
    node3->AddNode(node4);
    auto p_forDelete = node->SwapNextNode(node3);
    int i = node->GetValue();
    LinkedNode<int>::RemoveNode(p_forDelete);
    LinkedNode<int>::RemoveNode(node3);
    LinkedNode<int>::RemoveNode(node);


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
    

    const string stringFormat;
    const auto rnd = new Rnd();
    unsigned long long digital = rnd->GetRandom();
    cout << digital << endl;
    rnd->SetMinMax(100, 1000);
    digital = rnd->GetRandom();
    cout << digital << endl;
}