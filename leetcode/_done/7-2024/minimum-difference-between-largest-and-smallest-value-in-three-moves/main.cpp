#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

// daily-question 2024-07-03
class Solution
{
public:
    int calc(vector<int> nums, int step)
    {
        if (nums.size() == 0)
            return 0;
        if (step == 0)
            return nums.back() - nums.front();
        int last = nums.back();
        nums.erase(nums.end() - 1);
        int removeLast = calc(nums, step - 1);
        nums.push_back(last);
        nums.erase(nums.begin());
        int removeFirst = calc(nums, step - 1);

        return min(removeLast, removeFirst);
    }

    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return calc(nums, 3);
    }
};

int main()
{
    vector<int> inp = {1, 5, 0, 10, 14};
    Solution *solution = new Solution();
    solution->minDifference(inp);
    cout << "Hello world";
}