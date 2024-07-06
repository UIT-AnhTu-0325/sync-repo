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
    bool isPalindrome(string s) {
        string build = "";
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                build += s[i];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                build += (s[i] - 'A' + 'a');
            }
        }
        for (int i = 0; i < build.length() / 2; i++) {
            if (build[i] != build[build.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}