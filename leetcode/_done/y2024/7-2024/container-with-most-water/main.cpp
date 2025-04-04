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

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        vector<pair<int, int>> calc = {{0, height[0]}};
        for (int i = 1; i < n; i++) {
            if (height[i] > calc.back().second) {

                calc.push_back({i, height[i]});
            }
        }

        vector<int> tallestLeft = {height[n - 1]};
        for (int i = n - 2; i >= 0; i--) {
            tallestLeft.insert(tallestLeft.begin(), max(height[i], tallestLeft.front()));
        }

        int res = 0;
        for (int i = 0; i < calc.size(); i++) {
            for (int j = calc[i].first + 1; j < tallestLeft.size(); j++) {
                res = max(res, min(tallestLeft[j], calc[i].second) * (j - calc[i].first));
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}