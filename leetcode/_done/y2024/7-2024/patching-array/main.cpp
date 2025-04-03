#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-16
// think easier. when we can fill from 1 => n with n, we can fill from 1 => 2*n
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int result = 0;
        size_t i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                result++;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> inp = {1, 5, 10};
    Solution *solution = new Solution();
    solution->minPatches(inp, 20);
    cout << "Hello world";
}