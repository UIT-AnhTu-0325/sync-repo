#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-21
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            vector<vector<int>> res;
            res.push_back(vector<int>());
            return res;
        }
        int last = nums[nums.size() - 1];
        nums.pop_back();
        vector<vector<int>> excludeSub = subsets(nums);
        vector<vector<int>> result(excludeSub.begin(), excludeSub.end());

        for (int i = 0; i < excludeSub.size(); i++)
        {
            excludeSub[i].push_back(last);
        }
        for (int i = 0; i < excludeSub.size(); i++)
        {
            result.push_back(excludeSub[i]);
        }
        return result;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp;
    inp.push_back(0);
    solution->subsets(inp);
    cout << "Hello world";
}