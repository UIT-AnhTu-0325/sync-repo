#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
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
    void reorderList(ListNode *head)
    {
        // head = new ListNode(1);
        // ListNode *tmp = head;
        // tmp->next = new ListNode(2);
        // tmp = tmp->next;
        // tmp->next = new ListNode(3);
        // tmp = tmp->next;
        // tmp->next = new ListNode(4);
        // tmp = tmp->next;

        vector<ListNode *> vec;
        while (head != nullptr)
        {
            vec.push_back(head);
            head = head->next;
        }

        bool flagHead = false;

        ListNode *res = vec[0];
        head = vec[0];
        vec.erase(vec.begin());

        while (!vec.empty())
        {
            if (flagHead)
            {
                head->next = vec[0];
                vec.erase(vec.begin());
            }
            else
            {
                head->next = vec[vec.size() - 1];
                vec.erase(vec.end() - 1);
            }
            flagHead = !flagHead;
            head = head->next;
        }
        head->next = nullptr;
        head = res;
    }
};

int main()
{
    Solution *solution = new Solution();
    ListNode *head = nullptr;
    solution->reorderList(head);
    cout << "Hello world";
}