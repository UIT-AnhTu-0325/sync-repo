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

// daily-question 2024-08-01
class Solution {
  public:
    int countSeniors(vector<string> &details) {
        int ans = 0;
        for (auto &x : details) {
            int age = stoi(x.substr(11, 2));
            ans += age > 60;
        }
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}