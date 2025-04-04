#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// Skip bitwise for now, so hard to imagine
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<int, int> count;
        int mask = 0;
        count[0] = 1;
        long long result = 0;
        for (char c : word)
        {
            mask ^= 1 << (c - 'a');
            result += count[mask];
            for (int i = 0; i < 10; i++)
            {
                result += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return result;
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}