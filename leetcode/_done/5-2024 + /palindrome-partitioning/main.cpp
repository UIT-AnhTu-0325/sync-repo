#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-22
class Solution
{
public:
    vector<vector<bool>> checked;
    int n;
    vector<vector<string>> result;

    void
    markchecked(string s)
    {
        checked = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            checked[i][i] = true;
        }
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            if (j < n && s[i] == s[j])
            {
                checked[i][j] = true;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 2; i + j < n; j++)
            {
                if (s[i] == s[i + j] && checked[i + 1][i + j - 1])
                {
                    checked[i][i + j] = true;
                }
            }
        }
    }

    void back_track(vector<string> build, int start, string s)
    {
        if (start == n)
        {
            result.push_back(build);
            return;
        }

        for (int i = start; i < n; i++)
        {
            if (!checked[start][i])
                continue;
            build.push_back(s.substr(start, i - start + 1));
            back_track(build, i + 1, s);
            build.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        n = s.length();
        markchecked(s);
        back_track(vector<string>(), 0, s);
        return result;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}