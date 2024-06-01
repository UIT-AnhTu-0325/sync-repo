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
    string minRemoveToMakeValid(string s)
    {

        stack<int> stak;
        stack<int> remo;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '(' && s[i] != ')')
                continue;
            if (s[i] == '(')
                stak.push(i);
            else
            {
                if (stak.empty())
                {
                    remo.push(i);
                }
                else
                {
                    stak.pop();
                }
            }
        }

        while (!stak.empty())
        {
            s.erase(stak.top(), 1);
            stak.pop();
        }
        while (!remo.empty())
        {
            s.erase(remo.top(), 1);
            remo.pop();
        }

        return s;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->minRemoveToMakeValid("");
    cout << "Hello world";
}