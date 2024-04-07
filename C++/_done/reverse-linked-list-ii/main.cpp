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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        //  head = new ListNode(1, new ListNode(2));
        int count = 1;
        ListNode *crr = head;
        ListNode *preCrr = nullptr;
        while (left > count)
        {
            preCrr = crr;
            crr = crr->next;
            count++;
        }

        if (right == count)
            return head;

        ListNode *hold = crr;
        ListNode *build = nullptr;

        while (right >= count)
        {
            ListNode *tmp = hold->next;
            hold->next = build;
            build = hold;
            hold = tmp;

            count++;
        }
        if (left == 1)
        {
            crr = build;
            head = crr;
        }
        else
        {
            preCrr->next = build;
        }
        while (crr->next != nullptr)
        {
            crr = crr->next;
        }
        crr->next = hold;

        return head;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->reverseBetween(nullptr, 2, 4);
    cout << "Hello world";
}