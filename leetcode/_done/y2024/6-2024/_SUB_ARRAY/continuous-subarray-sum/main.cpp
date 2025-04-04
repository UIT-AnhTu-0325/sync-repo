#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-08
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        nums.insert(nums.begin(), 0);
        unordered_map<int, int> noted;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int iMod = sum % k;
            if (noted.find(iMod) == noted.end())
            {
                noted[iMod] = i;
            }
            else if (i - noted[iMod] > 2)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp = {23, 2, 4, 6, 6};
    solution->checkSubarraySum(inp, 7);
    cout << "Hello world";
}