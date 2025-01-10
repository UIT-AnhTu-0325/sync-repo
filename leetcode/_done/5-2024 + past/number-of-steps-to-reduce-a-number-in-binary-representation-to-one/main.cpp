#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-29
class Solution
{
public:
    int numSteps(string s)
    {
        int count = 0;
        int tmp = 0;
        for (int i = s.length() - 1; i > 0; i--)
        {
            s[i] += tmp;
            count++;
            if (s[i] == '0')
            {
                tmp = 0;
            }
            else if (s[i] == '1')
            {
                s[i]++;
                tmp = 0;
                i++;
            }
            else if (s[i] == '2')
            {
                tmp = 1;
            }
        }
        s[0] += tmp;

        if (s[0] == '2')
        {
            count++;
        }

        return count;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->numSteps("1101");
    cout << "Hello world";
}