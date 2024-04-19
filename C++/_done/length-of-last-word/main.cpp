#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int last = 0;

        stack<char> c;
        for (int i = 0; i < s.length(); i++)
        {
            if (i > 1 && s[i - 1] == ' ' && s[i] != ' ')
            {
                c = stack<char>();
            }
            if (s[i] != ' ')
                c.push(s[i]);
        }
        return c.size();
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}