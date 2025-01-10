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

// daily-question 2024-03-05
class Solution {
  public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;

        char crrChar = s[0];
        while (left < right && s[left] == crrChar && s[right] == crrChar) {
            while (s[left] == crrChar && left <= right) {
                left++;
            }
            while (s[right] == crrChar && left <= right) {
                right--;
            }

            if (s[left] == s[right]) {
                crrChar = s[left];
            }
        }

        return right - left + 1;
    }
};
int main() {
    string s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
    Solution *solution = new Solution();
    solution->minimumLength(s);
    cout << "Hello world";
}