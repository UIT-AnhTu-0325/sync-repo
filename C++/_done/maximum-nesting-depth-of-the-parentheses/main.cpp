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
    int maxDepth(string s)
    {
        stack<int> stak;
        int mx = INT32_MIN;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stak.push(i);
            }
            if (s[i] == ')')
            {
                stak.pop();
            }
            int size = stak.size();
            mx = max(mx, size);
        }

        return mx;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}