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
    ListNode *partition(ListNode *head, int x)
    {
        //head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));

        ListNode *left = new ListNode(INT32_MAX);
        ListNode *right = new ListNode(INT32_MAX);

        ListNode *headLeft = left;
        ListNode *headRight = right;

        while (head != nullptr)
        {
            if (head->val >= x)
            {
                right->next = head;
                right = right->next;
            }
            else
            {
                left->next = head;
                left = left->next;
            }
            head = head->next;
        }
        right->next = nullptr;
        left->next = headRight->next;
        return headLeft->next;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->partition(nullptr, 3);
    cout << "Hello world";
}