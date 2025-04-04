#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-21
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int res = 0;
        int total = 0;
        for (int i = 0; i < minutes; i++)
        {
            total += customers[i];
        }
        for (int i = minutes; i < customers.size(); i++)
        {
            total += ((grumpy[i] == 1) ? 0 : customers[i]);
        }
        res = max(total, res);
        int left = 0, right = minutes - 1;
        while (right < customers.size() - 1)
        {
            right++;
            total += ((grumpy[right] == 1) ? customers[right] : 0);
            total -= ((grumpy[left] == 1) ? customers[left] : 0);
            left++;
            res = max(total, res);
        }
        return res;
    }
};

int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    Solution *solution = new Solution();
    solution->maxSatisfied(customers, grumpy, minutes);
    cout << "Hello world";
}