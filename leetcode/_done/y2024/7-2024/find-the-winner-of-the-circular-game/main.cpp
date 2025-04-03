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

// daily-question 2024-07-08
// O(n) time and  O(1) space
class Solution {
  public:
    int solve(int n, int k) {
        if (n == 1) {
            return 0;
        }
        return (solve(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) { return solve(n, k) + 1; }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}