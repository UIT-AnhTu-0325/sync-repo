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
        if (index == -1)
            return;
        int tmp = nums[index];
        nums[index] = -1;
        markDone(nums, tmp);
    }

    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] -= 1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            markDone(nums, nums[i]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != -1)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}