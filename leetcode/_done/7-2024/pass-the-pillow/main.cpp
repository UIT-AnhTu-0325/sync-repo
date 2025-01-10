#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>s
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question 2024-07-06
class Solution {
  public:
    int passThePillow(int n, int time) {
        int mod = time % (2 * n - 2);
        return mod > (n - 1) ? n - (mod - n) - 1 : mod + 1;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}