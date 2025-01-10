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

// daily-question 2024-07-12
class Solution {
  public:
    int solve(string s, int x, int y) {
        char charMax = x > y ? 'a' : 'b';
        char charMin = charMax == 'a' ? 'b' : 'a';
        int valMax = charMax == 'a' ? x : y;
        int valMin = valMax == x ? y : x;
        int res = 0;

        stack<char> calc;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == charMin && !calc.empty() && calc.top() == charMax) {
                res += valMax;
                calc.pop();
            } else {
                calc.push(s[i]);
            }
        }

        int numMax = 0;
        while (!calc.empty() && calc.top() == charMax) {
            numMax++;
            calc.pop();
        }
        while (!calc.empty() && calc.top() == charMin && numMax > 0) {
            numMax--;
            res += valMin;
            calc.pop();
        }

        return res;
    }

    int maximumGain(string s, int x, int y) {
        string tmp = "";
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'b') {
                tmp += s[i];
            } else {
                res += solve(tmp, x, y);
                tmp = "";
            }
        }

        res += solve(tmp, x, y);
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}