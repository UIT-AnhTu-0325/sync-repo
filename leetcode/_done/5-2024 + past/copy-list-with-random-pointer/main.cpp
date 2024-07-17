#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, Node *> u;
    
    while (temp != nullptr)
    {
        u[temp] = new Node(temp->val);
        temp = temp->next;
    }
    
    temp = head;
    
    while (temp != nullptr)
    {
        Node *curr = u[temp];
        Node *nex = u[temp->next];  
        Node *r = u[temp->random];
        curr->next = nex;
        curr->random = r;
        temp = temp->next;
    }

    return u[head];
}

int main()
{
}