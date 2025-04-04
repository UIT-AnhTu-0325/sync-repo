#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-30

// My solution => 0(n^2)
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int crrXor = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                crrXor ^= arr[j];
                if (crrXor == 0)
                {
                    count += j - i;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}