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

// daily-question&envId=2024-07-29
class Solution {
   public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> build1 = vector<int>(n, 0);
        vector<int> build2 = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[j] > rating[i]) {
                    build1[i]++;
                } else {
                    build2[i]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[j] > rating[i]) {
                    res += build1[j];
                } else {
                    res += build2[j];
                }
            }
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}