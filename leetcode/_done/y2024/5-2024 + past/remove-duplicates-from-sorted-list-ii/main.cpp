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
    ListNode *deleteDuplicates(ListNode *head)
    {
        head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));

        ListNode *shadow = new ListNode(INT32_MAX, head);

        ListNode *p1 = shadow;
        ListNode *p2 = shadow->next;

        int cnt = 0;

        while (p1->next != nullptr)
        {

            while (p2 != nullptr && p2->next != nullptr && p2->next->val == p2->val)
            {
                p2 = p2->next;
                cnt++;
            }

            p2 = p2->next;

            if (cnt >= 1)
            {
                p1->next = p2;
                cnt = 0;
            }
            else
            {
                p1 = p1->next;
            }
        }
        return shadow->next;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->deleteDuplicates(nullptr);
    cout << "Hello world";
}