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
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int res = INT32_MAX;
        unordered_map<int, int> umap;
        int cnt = 0;
        while (right < nums.size())
        {
            if (umap.find(nums[right]) == umap.end())
                umap[nums[right]] = 1;
            else
            {
                umap[nums[right]]++;
                cnt++;
            }
            while (nums[right] - nums[left] >= nums.size())
            {
                if (umap[nums[left]] > 1)
                    cnt--;
                umap[nums[left]]--;
                left++;
            }

            res = min(res, (int)nums.size() - (right - left + 1 - cnt));
            right++;
        }
        return res;
    }
};

int main()
{
    vector<int> inp = {1, 2, 3, 5, 6};
    Solution *solution = new Solution();
    solution->minOperations(inp);
    cout << "Hello world";
}