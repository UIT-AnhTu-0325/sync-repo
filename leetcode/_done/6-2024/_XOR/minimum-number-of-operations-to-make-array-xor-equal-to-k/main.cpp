#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

class Solution
{
    int SIZE = 100;

public:
    int minOperations(vector<int> &nums, int k)
    {
        vector<int> calc = vector<int>(SIZE, 0);
        for (int num : nums)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (num == 0)
                    break;
                calc[i] += num % 2;
                num >>= 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (k % 2 != calc[i] % 2)
            {
                ans++;
            }
            k >>= 1;
        }
        return ans;
    }
};

class Solution2
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        bitset<20> xorSum = k;
        for (int x : nums)
            xorSum ^= x;
        return xorSum.count();
    }
};

int main()
{
    vector<int> inp = {4};
    Solution *solution = new Solution();
    solution->minOperations(inp, 7);
    cout << "Hello world";
}