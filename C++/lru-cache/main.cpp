#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
    }

    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }
};

int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    int param_1 = obj->get(1);
    obj->put(3, 3);
    int param_2 = obj->get(2);
    cout << "Hello world";
}