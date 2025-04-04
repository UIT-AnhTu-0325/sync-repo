#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-12
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            int crrNum = nums[i];
            if (nums[i] == 0)
            {
                int j = i + 1;
                while (j < nums.size() && nums[j] == 0)
                {
                    j++;
                }
                nums.erase(nums.begin() + i, nums.begin() + j);
                nums.insert(nums.begin(), j - i, 0);
            }
            else if (nums[i] == 2)
            {
                int j = i + 1;
                while (j < nums.size() && nums[j] == 2)
                {
                    j++;
                }
                nums.erase(nums.begin() + i, nums.begin() + j);
                nums.insert(nums.end(), j - i, 2);
            }
            if (crrNum != nums[i])
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}