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

// daily-question 2024-07-10
class Solution {
  public:
    int minOperations(vector<string> &logs) {
        int res = 0;
        for (string step : logs) {
            if (step[0] == '.' && step[1] == '.') {
                res = max(0, res - 1);
            } else if (step[0] == '.' && step[1] == '/') {
                continue;
            } else {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}