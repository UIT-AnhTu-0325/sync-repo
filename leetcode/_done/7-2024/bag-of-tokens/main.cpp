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

// daily-question 2024-03-04
class Solution {
  public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int res = 0;
        int left = 0, right = tokens.size() - 1;

        bool action = true;
        while (left <= right && action) {
            action = false;
            while (left <= right && power >= tokens[left]) {
                power -= tokens[left];
                left++;
                res++;
                action = true;
            }
            if (right > left && tokens[right] >= tokens[left] && res > 0) {
                power += tokens[right];
                right--;
                res--;
                action = true;
            }
        }

        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}