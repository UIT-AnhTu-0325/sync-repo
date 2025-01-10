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
    bool checkValidString(string s)
    {
        stack<int> star;
        stack<int> open;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open.push(i);
            else if (s[i] == '*')
                star.push(i);
            else
            {
                if (star.empty() && open.empty())
                    return false;
                else if (!open.empty())
                {
                    open.pop();
                }
                else
                {
                    star.pop();
                }
            }
        }

        while (!open.empty())
        {
            if (star.empty())
                return false;

            if (star.top() < open.top())
                return false;
            star.pop();
            open.pop();
        }

        return true;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->checkValidString("(*(*");
    cout << "Hello world";
}