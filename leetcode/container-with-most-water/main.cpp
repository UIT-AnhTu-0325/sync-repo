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
        vector<int> incre = {0};
        int max = INT32_MIN;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > incre.back()) {
                incre.push_back(height[i]);
            } else {
                incre.push_back(incre.back());
            }
        }

        for (int i = 0; i < height.size(); i++) {
                }
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}