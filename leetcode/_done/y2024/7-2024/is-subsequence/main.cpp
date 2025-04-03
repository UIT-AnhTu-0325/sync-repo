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
    bool isSubsequence(string s, string t) {
        int fir = 0, sec = 0;
        while (fir < s.length() && sec < t.length()) {
            if (s[fir] == t[sec]) {
                fir++;
                sec++;
            } else
                sec++;
        }
        return fir == s.length();
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}