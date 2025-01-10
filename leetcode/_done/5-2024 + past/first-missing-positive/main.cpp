#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    void markDone(vector<int> &nums, int index)
    {
        if (index <= -1 || index >= nums.size() || nums[index == index])
            return;
        int tmp = nums[index];
        nums[index] = index;
        markDone(nums, tmp);
    }
    int firstMissingPositive(vector<int> &nums)
    {
        vector<int> res;

        nums.insert(nums.begin(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            markDone(nums, nums[i]);
        }

        int i = 1;

        for (i; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }

        return i;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}