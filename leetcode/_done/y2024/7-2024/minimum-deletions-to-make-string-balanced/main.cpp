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

// daily-question&envId=2024-07-30
class Solution {
   public:
    int minimumDeletions(string s) {
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}