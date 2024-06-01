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
    int pivotInteger(int n)
    {
        double x = sqrt(n * (n + 1) / 2.0);

        if (fmod(x, 1.0) != 0)
        {
            return -1;
        }
        else
        {
            return static_cast<int>(x);
        }
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}