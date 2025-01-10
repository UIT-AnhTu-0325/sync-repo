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

// daily-question 2024-03-08
class Solution {
  public:
    int maxFrequencyElements(vector<int> &nums) {
        unordered_map<int, int> calc;
        int maxi = 0;
        for (int num : nums) {
            if (calc.find(num) == calc.end()) {
                calc[num] = 1;
            } else {
                calc[num]++;
            }
            maxi = max(maxi, calc[num]);
        }
        int res = 0;
        for (pair<int, int> p : calc) {
            if (p.second == maxi)
                res += maxi;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}