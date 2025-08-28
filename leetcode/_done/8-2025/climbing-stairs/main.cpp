#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    vector<int> dp = vector<int>(100, -1);

public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 3;
        if (dp[n] != -1)
            return dp[n];
        int crrDp = climbStairs(n - 1) + climbStairs(n - 2);
        dp[n] = crrDp;
        return crrDp;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}