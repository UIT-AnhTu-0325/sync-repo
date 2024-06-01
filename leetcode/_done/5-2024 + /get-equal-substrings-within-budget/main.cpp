#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-28
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int maxx = 0, cal = 0;
        int l = 0, r = 0;
        while (r < s.length())
        {
            cal += (abs(s[r] - t[r]));
            while (cal > maxCost)
            {
                cal -= (abs(s[l] - t[l]));
                l++;
            }
            maxx = max(maxx, r - l + 1);
            r++;
        }
        return maxx;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}