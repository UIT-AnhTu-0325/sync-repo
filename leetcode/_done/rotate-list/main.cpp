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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }

        int n = 0;
        ListNode *tmp = head;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            n++;
        }
        k = k % n;

        if (k == 0)
        {
            return head;
        }

        ListNode *p1 = head;

        int keep = n - k;
        while (keep > 1)
        {
            p1 = p1->next;
            keep--;
        }

        ListNode *newHead = p1->next;
        p1->next = nullptr;
        p1 = newHead;
        while (p1 != nullptr && p1->next != nullptr)
        {
            p1 = p1->next;
        }
        p1->next = head;

        return newHead;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}