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

// daily-question&envId=2024-07-24
class Solution {
   public:
    int mapInt(vector<int>& mapping, int x) {
        if (x == 0) return mapping[0];  //  edge case
        int z = 0;
        for (int pow10 = 1; x > 0; pow10 *= 10) {
            auto [q, r] = div(x, 10);
            z += mapping[r] * pow10;
            x = q;
        }
        return z;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> calc;
        for (int num : nums) {
            int mapped = mapInt(mapping, num);
            calc[num] = mapped;
        }
        sort(nums.begin(), nums.end(),
             [&calc](const int& a, const int& b) { return calc[a] < calc[b]; });
        return nums;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}