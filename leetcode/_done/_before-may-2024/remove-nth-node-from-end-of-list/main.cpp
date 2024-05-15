#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *beforeP2 = nullptr;
        int tmp = n;
        while (n > 0)
        {
            p1 = p1->next;
            n--;
        }
        while (p1 != nullptr)
        {
            p1 = p1->next;
            beforeP2 = p2;
            p2 = p2->next;
        }

        if (beforeP2 == nullptr)
            return head->next;

        beforeP2->next = p2->next;
        return head;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}