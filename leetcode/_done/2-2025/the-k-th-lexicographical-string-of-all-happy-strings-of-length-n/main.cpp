#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        if (k > 3 * pow(2, n))
            return "";

        string result(n, 'a');
        int startByA = 1;
        int startByB = startByA + pow(2, n - 1);
        int startByC = startByB + pow(2, n - 1);

        if (k >= startByA && k < startByB)
        {
            result[0] = 'a';
            k -= startByA;
        }
        else if (k >= startByB && k < startByC)
        {
            result[0] = 'b';
            k -= startByB;
        }
        else
        {
            result[0] = 'c';
            k -= startByC;
        }

        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        for (int i = 1; i < n; i++)
        {
            int midPoint = pow(2, n - i - 1);
            if (k < midPoint)
            {
                result[i] = nextSmallest[result[i - 1]];
            }
            else
            {
                result[i] = nextGreatest[result[i - 1]];
                k -= midPoint;
            }
        }
        return result;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}