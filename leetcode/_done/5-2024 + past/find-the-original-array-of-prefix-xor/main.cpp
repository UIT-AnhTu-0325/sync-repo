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
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> res;
        res.push_back(pref.front());
        for (int i = 1; i < pref.size(); i++)
        {
            res.push_back(pref[i - 1] ^ pref[i]);
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}