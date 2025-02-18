#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
using namespace std;
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }

    ListNode *divideAndConquer(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];

        int mid = left + (right - left) / 2;
        ListNode *l1 = divideAndConquer(lists, left, mid);
        ListNode *l2 = divideAndConquer(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
};

class Solution2
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> res;
        vector<int> crr;
        for (int i = 0; i < lists.size(); i++)
        {
            int crrIdx = 0;
            while (crrIdx < crr.size() && lists[i] != nullptr)
            {
                int crrMax = min(crr[crrIdx], lists[i]->val);
                res.push_back(crrMax);
                if (crr[crrIdx] == crrMax)
                    crrIdx++;
                else
                    lists[i] = lists[i]->next;
            }
            while (crrIdx < crr.size())
            {
                res.push_back(crr[crrIdx]);
                crrIdx++;
            }
            while (lists[i] != nullptr)
            {
                res.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
            crr = res;
            res = {};
        }

        ListNode *result = nullptr;
        ListNode *point = nullptr;
        for (int i = 0; i < crr.size(); i++)
        {
            ListNode *node = new ListNode(crr[i]);
            if (i == 0)
            {
                point = node;
                result = point;
            }
            else
            {
                point->next = node;
                point = point->next;
            }
        }
        return result;
    }
};

ListNode *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    Solution *solution = new Solution();

    // vector<vector<int>> arrays = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<vector<int>> arrays = {};
    vector<ListNode *> lists;
    for (const auto &arr : arrays)
    {
        lists.push_back(createLinkedList(arr));
    }
    solution->mergeKLists(lists);

    cout << "Hello world";
}