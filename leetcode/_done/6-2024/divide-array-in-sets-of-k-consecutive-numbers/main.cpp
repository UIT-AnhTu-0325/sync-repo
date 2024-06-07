#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    bool checkGroup(vector<int> &nums, int start, int k)
    {
        int count = 1;
        int nextNum = nums[start] + 1;
        nums[start] = -1;
        start++;

        while (count < k)
        {
            if (start >= nums.size())
                return false;
            if (nums[start] == nextNum)
            {
                nextNum++;
                nums[start] = -1;
                count++;
            }
            else if (nums[start] != nextNum - 1 && nums[start] >= 0)
                return false;
            start++;
        }
        return true;
    }

    bool isPossibleDivide(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                continue;
            if (!checkGroup(nums, i, k))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp = {1, 2, 3, 3, 4, 4, 5, 6};
    solution->isPossibleDivide(inp, 4);
    cout << "Hello world";
}