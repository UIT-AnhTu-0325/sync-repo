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
    string makeGood(string s)
    {
        stack<char> stak;
        for (int i = 0; i < s.size(); i++)
        {
            if (stak.empty())
            {
                stak.push(s[i]);
            }
            else
            {
                char last = stak.top();
                if (last == s[i] + 32 || last == s[i] - 32)
                {
                    stak.pop();
                }
                else
                {
                    stak.push(s[i]);
                }
            }
        }
        string res = "";
        while (!stak.empty())
        {
            res = stak.top() + res;
            stak.pop();
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}