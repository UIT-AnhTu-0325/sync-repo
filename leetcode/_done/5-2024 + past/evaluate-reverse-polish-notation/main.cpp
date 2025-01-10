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
    bool isNumber(string str)
    {
        if (str.empty())
        {
            return false; // Empty string is not an integer
        }

        size_t start = 0;

        // Check for negative sign
        if (str[0] == '-')
        {
            if (str.length() == 1)
            {
                return false; // Just a negative sign, not a valid integer
            }
            start = 1; // Start checking from the next character
        }

        // Check each character in the remaining string
        for (size_t i = start; i < str.length(); ++i)
        {
            if (!std::isdigit(str[i]))
            {
                return false; // Non-digit character found
            }
        }

        return true; // All characters are digits
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> cal;
        if (tokens.size() == 1)
            return stoi(tokens[0]);
        for (int i = 0; i < tokens.size(); i++)
        {
            if (isNumber(tokens[i]))
            {
                cal.push(stoi(tokens[i]));
            }
            else
            {
                int t1 = cal.top();
                cal.pop();
                int t2 = cal.top();
                cal.pop();
                int tmp = 0;

                if (tokens[i] == "+")
                {
                    tmp = t1 + t2;
                }
                else if (tokens[i] == "-")
                {
                    tmp = t2 - t1;
                }
                else if (tokens[i] == "*")
                {
                    tmp = t2 * t1;
                }
                else if (tokens[i] == "/")
                {
                    tmp = t2 / t1;
                }
                cal.push(tmp);
            }
        }
        return cal.top();
    }
};

int main()
{
    vector<string> s = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution *solution = new Solution();
    solution->evalRPN(s);
}