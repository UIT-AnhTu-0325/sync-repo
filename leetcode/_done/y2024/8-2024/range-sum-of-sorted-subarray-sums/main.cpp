#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question 2024-08-04
class Solution {
   public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> storeSubarray;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            // Iterate through all indices ahead of the current index.
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                storeSubarray.push_back(sum);
            }
        }
        // Sort all subarray sum values in increasing order.
        sort(storeSubarray.begin(), storeSubarray.end());

        // Find the sum of all values between left and right.
        int rangeSum = 0, mod = 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++) {
            rangeSum = (rangeSum + storeSubarray[i]) % mod;
        }
        return rangeSum;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}