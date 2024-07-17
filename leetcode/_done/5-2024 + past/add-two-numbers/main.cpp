#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* t = head;
    int hold = 0;
    while(l1 != nullptr && l2 != nullptr)
    {
        t->val = l1->val + l2->val + hold;
        if(t->val >= 10 )
        {
            t->val -= 10;
            hold = 1;
        }
        else
        {
            hold = 0;
        }
        if(l1->next !=nullptr || l2->next !=nullptr)
        {

        ListNode* tmp = new ListNode();
        t->next = tmp;
        t = t->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != nullptr)
    {
        t->val = hold + l1->val;
        if(t->val >= 10)
        {
            t->val -= 10;
            hold = 1;
        }
        else
        {
            hold = 0;
        }
        
        if(l1->next != nullptr)
        {
            ListNode* tmp = new ListNode();
            t->next = tmp;
            t = t->next;
        }
        l1 = l1->next;
    }
    while(l2 != nullptr)
    {
        t->val = hold + l2->val;
        if(t->val >= 10)
        {
            t->val -= 10;
            hold = 1;
        }
        else
        {
            hold = 0;
        }
        if(l2->next != nullptr)
        {

            ListNode* tmp = new ListNode();
            t->next = tmp;
            t = t->next;
        }
        
        l2 = l2->next;
    }
    if(hold == 1)
    {
        ListNode* tmp = new ListNode(1);
        t->next = tmp;
    }
    return head;
}

int main()
{

}