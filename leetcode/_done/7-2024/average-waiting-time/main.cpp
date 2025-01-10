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

// daily-question 2024-07-09
class Solution {
  public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        vector<int> waitTime;
        int crrTime = 1;
        for (int i = 0; i < customers.size(); i++) {
            crrTime = max(customers[i][0], crrTime) + customers[i][1];
            waitTime.push_back(crrTime - customers[i][0]);
        }
        double res = 0;
        for (int time : waitTime) {
            res += time;
        }
        res /= waitTime.size();
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}