#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-04
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end(), greater<int>());
        int res = 0;
        int i = 0,
            j = people.size() - 1;
        while (i <= j)
        {
            if ((people[i] + people[j]) <= limit)
            {
                i++;
                j--;
            }
            else
            {
                i++;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    vector<int> inp = {3, 2, 2, 1};
    Solution *solution = new Solution();
    solution->numRescueBoats(inp, 3);
    cout << "Hello world";
}