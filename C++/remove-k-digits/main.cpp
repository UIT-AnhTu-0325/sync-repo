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
    string solve(string &num, int k)
    {
        if (k == 0)
            return num;

        if (num.length() <= k)
            return "";

        int crr = 0;

        while (num.length() > 0 && num[0] == '0')
        {
            num.erase(0, 1);
        }

        for (int i = 0; i <= k; i++)
        {
            if (num[i] < num[crr])
            {
                crr = i;
            }
        }

        if (crr == 0)
        {
            if (num[k] == '0')
            {
                return solve(num.erase(0, k), 0);
            }

            return num[0] + solve(num.erase(0, 1), k);
        }
        else
        {
            num.erase(0, crr);

            return solve(num, k -= (crr));
        }
    }

    string removeKdigits(string num, int k)
    {
        string res = solve(num, k);
        while (res.length() > 0 && res[0] == '0')
        {
            res.erase(0, 1);
        }
        if (res.length() == 0)
            return "0";
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->removeKdigits("112", 1);
    cout << "Hello world";
}