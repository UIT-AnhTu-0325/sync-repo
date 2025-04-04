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

// daily-question 2024-07-23
class Solution {
   public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> build;
        for (int num : nums) {
            build[num]++;
        }

        sort(nums.begin(), nums.end(), [&build](const int& a, const int& b) {
            return build[a] == build[b] ? a > b : build[a] > build[b];
        });

        return nums;
    }
};
int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}