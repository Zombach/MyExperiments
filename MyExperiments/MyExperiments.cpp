#include <iostream>
#include "Rnd.h"
#include <format>
#include <fstream>

#include "Dictionary.h"
#include "Hash.h"
#include "LinkedNode.h"


using namespace std;
using namespace zloo;

int main()
{
    string fish = "fish";
    const auto dict = new Dictionary<string, string>();
    bool is_add = dict->TryAdd("1", &fish);
    cout << is_add << endl;
    is_add = dict->TryAdd("21", &fish);
    cout << is_add << endl;
    is_add = dict->TryAdd("2", &fish);
    cout << is_add << endl;
    string value;
    bool is_get = dict->TryGetValue("1", value);
    cout << is_add << endl;
    is_get = dict->TryGetValue("21", value);
    cout << is_add << endl;

    int i = 1;
    auto node = new LinkedNode<int, int>(i);
    auto node2 = new LinkedNode<int, int>(i);
    auto node3 = new LinkedNode<int, int>(i);
    auto node4 = new LinkedNode<int, int>(i);
    node->AddNode(node2);
    node2->AddNode(node3);
    node3->AddNode(node4);
    auto p_forDelete = node->SwapNextNode(node3);
    auto t = node->GetValue();
    LinkedNode<int, int>::RemoveNode(p_forDelete);
    LinkedNode<int, int>::RemoveNode(node3);
    LinkedNode<int, int>::RemoveNode(node);


    const auto hash = new Hash<string>();
    string key = "world";
    int code = hash->GetHash(key);


	
    

    const string stringFormat;
    const auto rnd = new Rnd();
    unsigned long long digital = rnd->GetRandom();
    cout << digital << endl;
    rnd->SetMinMax(100, 1000);
    digital = rnd->GetRandom();
    cout << digital << endl;
}