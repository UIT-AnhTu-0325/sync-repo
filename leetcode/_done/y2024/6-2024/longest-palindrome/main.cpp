#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-04
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> umap;
        for (char c : s)
        {
            if (umap.find(c) == umap.end())
                umap[c] = 1;
            else
                umap[c]++;
        }

        bool hasOdd = false;
        int count = 0;
        for (pair<char, int> p : umap)
        {
            count += p.second % 2 == 0 ? p.second : p.second - 1;
            if (p.second % 2 != 0)
            {
                hasOdd = true;
            }
        }
        if (hasOdd)
            count++;
        return count;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}