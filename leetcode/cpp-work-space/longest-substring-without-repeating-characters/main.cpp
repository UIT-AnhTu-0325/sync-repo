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
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = -1;
        int longest = 0;
        map<char, int> mem;
        int n = s.length();
        while (l < n && r < (n - 1))
        {
            r++;
            if (mem.find(s[r]) == mem.end())
            {
                mem[s[r]] = 1;
            }
            else
            {
                mem[s[r]]++;
            }
            while (mem[s[r]] > 1)
            {
                mem[s[l]]--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
int main()
{
    Solution *solution = new Solution();
    solution->lengthOfLongestSubstring("abcabcbb");
    cout << "Hello world";
}