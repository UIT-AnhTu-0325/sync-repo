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

// daily-question 2024-07-22
class Solution {
   public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (heights[i] < heights[j]) {
                    int tmp = heights[i];
                    string tmpStr = names[i];

                    heights[i] = heights[j];
                    names[i] = names[j];

                    heights[j] = tmp;
                    names[j] = tmpStr;
                }
            }
        }
        return names;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}