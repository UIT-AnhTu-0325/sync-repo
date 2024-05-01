#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        vector<int> builder = vector<int>(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            int begin = max(0, (s[i] - 'a') - k);
            int end = min(25, (s[i] - 'a') + k);

            int maxx = INT32_MIN;
            for (int j = begin; j <= end; j++)
            {
                maxx = max(maxx, builder[j]);
            }
            builder[s[i] - 'a'] = maxx + 1;
        }
        int ans = INT32_MIN;
        for (int i = 0; i <= 25; i++)
        {
            ans = max(ans, builder[i]);
        }
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    string s = "pvjcci";
    solution->longestIdealString(s, 4);
    cout << "Hello world";
}