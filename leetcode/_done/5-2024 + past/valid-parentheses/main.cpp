#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> chk = stack<char>();
    for (int i = 0; i < s.length(); i++)
    {
        if (chk.empty())
        {
            chk.push(s[i]);
        }
        else if (chk.top() == '(' && s[i] == ')')
        {
            chk.pop();
        }
        else if (chk.top() == '[' && s[i] == ']')
        {
            chk.pop();
        }
        else if (chk.top() == '{' && s[i] == '}')
        {
            chk.pop();
        }
        else
        {
            chk.push(s[i]);
        }
    }
    return (chk.empty() ? true : false);
}

int main()
{
    string a;
    getline(cin, a);
    cout << (isValid(a) ? "true" : "false");
}