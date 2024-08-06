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

// daily-question 2024-08-06
class Solution {
   public:
    int minimumPushes(string word) {
        map<char, int> builder;
        for (char c : word) {
            builder[c]++;
        }

        vector<pair<char, int>> sortedBuilder(builder.begin(), builder.end());

        sort(sortedBuilder.begin(), sortedBuilder.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        int time = 1, crrIdx = 1, res = 0;
        for (pair<char, int> item : sortedBuilder) {
            res += time * item.second;
            crrIdx++;
            if (crrIdx == 9) {
                time++;
                crrIdx = 1;
            };
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}