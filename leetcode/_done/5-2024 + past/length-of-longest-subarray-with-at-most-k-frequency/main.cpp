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
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        unordered_map<int, int> times;
        int crrLenMax = 0;
        while (right < nums.size())
        {
            if (times.find(nums[right]) == times.end())
            {
                times[nums[right]] = 1;
            }
            else
            {
                times[nums[right]]++;
            }

            while (times[nums[right]] > k)
            {
                times[nums[left]]--;
                left++;
            }

            crrLenMax = max(crrLenMax, right - left + 1);
            right++;
        }

        return crrLenMax;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}