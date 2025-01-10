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
    long long countSubarrays(vector<int> &nums, int k)
    {
        int max_num = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0, count = 0;
        long long ans = 0;
        while (right < nums.size())
        {
            if (nums[right] == max_num)
                count++;

            while (count >= k)
            {
                if (nums[left] == max_num)
                    count--;
                left++;
                ans += nums.size() - right;
            }
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}