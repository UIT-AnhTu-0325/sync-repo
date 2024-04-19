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
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long score;
        long long left = 0, right = 0, ans = 0, count = 0;
        while (right < nums.size())
        {
            score = count == 0
                        ? nums[right]
                        : (score / count + nums[right]) * (count + 1);
            count++;
            while (score >= k)
            {
                score = count <= 1
                            ? 0
                            : (score / count - nums[left]) * (count - 1);
                left++;
                count--;
            }
            ans += (right - left + 1);
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