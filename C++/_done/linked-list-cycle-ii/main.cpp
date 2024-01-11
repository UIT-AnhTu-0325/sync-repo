#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *find = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            while (fast != find)
            {
                fast = fast->next;
                find = find->next;
            }
            return find;
        }
    }
    return NULL;
}

int main()
{
}