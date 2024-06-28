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
    vector<int> divisibilityArray(string word, int m)
    {
        vector<int> res;
        long long crrMod = 0;
        for (char c : word)
        {
            crrMod = (crrMod * 10 + (long long)(c - '0')) % m;
            if (crrMod == 0)
                res.push_back(1);
            else
                res.push_back(0);
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->divisibilityArray("1010", 10);
    cout << "Hello world";
}