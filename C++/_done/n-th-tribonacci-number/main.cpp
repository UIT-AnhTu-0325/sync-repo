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
    unordered_map<int, int> res;

    Solution()
    {
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
    }

    int tribonacci(int n)
    {
        if (res.find(n) != res.end())
            return res[n];
        res[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return res[n];
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}