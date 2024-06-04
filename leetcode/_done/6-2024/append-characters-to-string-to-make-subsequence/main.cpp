#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-03
class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int idxS = 0, idxT = 0;
        while (idxS < s.size())
        {
            if (idxT >= t.size())
                return 0;
            if (s[idxS] == t[idxT])
            {
                idxT++;
            }
            idxS++;
        }
        return t.size() - idxT;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}