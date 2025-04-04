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

// daily-question 2024-07-07
// use some math can solve problem by O(n)
// but O(log(n)) still good
class Solution {
  public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int tmp = 0;
        while (numBottles > 0) {
            res += numBottles;
            numBottles += tmp;
            int drinked = numBottles;
            numBottles /= numExchange;
            tmp = drinked - numExchange * numBottles;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}