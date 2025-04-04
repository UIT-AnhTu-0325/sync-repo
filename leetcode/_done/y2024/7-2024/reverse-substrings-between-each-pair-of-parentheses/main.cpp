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

// daily-question 2024-07-11
class Solution {
  public:
    string reserveString(string s) {
        string res = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            res += s[i];
        }
        return res;
    }

    string reverseParentheses(string s) {
        stack<int> build;
        stack<string> calc;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                calc.push("");
            } else if (s[i] == ')') {
                string top = reserveString(calc.top());
                calc.pop();
                if (calc.empty()) {
                    calc.push("");
                }
                calc.top() += top;
            } else {
                if (calc.empty()) {
                    calc.push("");
                }
                calc.top() += s[i];
            }
        }
        string res = "";
        while (!calc.empty()) {
            res = calc.top() + res;
            calc.pop();
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    // solution->reverseParentheses("(u(love)i)");
    // solution->reverseParentheses("a(bcdefghijkl(mno)p)q");
    solution->reverseParentheses("sxmdll(q)eki(x)");
    cout << "Hello world";
}