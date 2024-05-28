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
    int solve(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        unordered_map<int, int> map_count;

        int ans = 0;

        while (right < nums.size())
        {
            int num = nums[right];

            if (map_count.find(num) == map_count.end())
            {
                map_count[num] = 1;
            }
            else
            {
                map_count[num]++;
            }

            while (map_count.size() > k && left <= right)
            {
                if (map_count[nums[left]] == 1)
                {
                    map_count.erase(nums[left]);
                }
                else
                {
                    map_count[nums[left]]--;
                }
                left++;
            }

            ans += (right - left + 1);

            right++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> a;
    solution->subarraysWithKDistinct(a, 2);
    cout << "Hello world";
}