#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node() : val(0), key(0), prev(nullptr), next(nullptr) {}
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    Node(int key, int val, Node *left, Node *right) : key(key), val(val), prev(left), next(right) {}
};
class LRUCache
{

public:
    int capa;
    unordered_map<int, Node *> umap;
    Node *head;
    Node *tail;
    LRUCache(int capacity)
    {
        capa = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
    }

    void addNode(int key, int val)
    {
        Node *newNode = new Node(key, val);
        if (umap.find(key) != umap.end())
        {
            removeNode(umap[key]);
        }
        capa--;
        umap[key] = newNode;
        if (head->next == nullptr)
        {
            head->next = newNode;
            newNode->prev = head;
            newNode->next = tail;
            tail->prev = newNode;
            return;
        }

        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
    }

    void removeNode(Node *delNode)
    {
        Node *tmpPrev = delNode->prev;
        Node *tmpNext = delNode->next;
        tmpPrev->next = tmpNext;
        tmpNext->prev = tmpPrev;
        umap.erase(delNode->key);
        capa++;
    }

    int get(int key)
    {

        if (umap.find(key) != umap.end())
        {
            int val = umap[key]->val;
            removeNode(umap[key]);
            addNode(key, val);
            return val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (umap.find(key) != umap.end())
        {
            removeNode(umap[key]);
        }
        addNode(key, value);

        if (capa < 0)
        {
            removeNode(head->next);
        }
    }
};

int main()
{
    // LRUCache *obj = new LRUCache(2);
    // obj->put(1, 1);
    // obj->put(2, 2);
    // int param_1 = obj->get(1);
    // obj->put(3, 3);
    // int param_2 = obj->get(2);
    // cout << "Hello world";

    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);    // return 4
}