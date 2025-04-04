#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question&envId=2024-07-13
class Solution {
  public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        unordered_map<int, int> umap;
        int maxVal = -1;
        for (int i = 0; i < positions.size(); i++) {
            umap[positions[i]] = i;
            maxVal = max(maxVal, positions[i]);
        }

        map<int, int> sorted_map(umap.begin(), umap.end());

        stack<int> calc;
        for (const auto &pair : sorted_map) {
            int i = pair.first;
            bool isIncomeDead = false;
            while (!calc.empty() && directions[umap[calc.top()]] == 'R' && directions[umap[i]] == 'L' &&
                   !isIncomeDead) {

                int firstVal = healths[umap[calc.top()]];
                int secVal = healths[umap[i]];
                int firstIdx = calc.top();
                int secIdx = i;

                if (firstVal > secVal) {
                    healths[umap[firstIdx]]--;
                    healths[umap[secIdx]] = -1;
                    isIncomeDead = true;
                } else if (firstVal < secVal) {
                    healths[umap[firstIdx]] = -1;
                    healths[umap[secIdx]]--;
                    calc.pop();
                } else {
                    healths[umap[firstIdx]] = -1;
                    healths[umap[secIdx]] = -1;
                    isIncomeDead = true;
                    calc.pop();
                }
            }

            if (!isIncomeDead) {
                calc.push(i);
            }
        }

        vector<int> res;
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] >= 0) {
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};

int main() {
    vector<int> positions = {11, 44, 16};
    vector<int> healths = {1, 20, 17};
    string directions = "RLR";
    Solution *solution = new Solution();
    solution->survivedRobotsHealths(positions, healths, directions);
    cout << "Hello world";
}