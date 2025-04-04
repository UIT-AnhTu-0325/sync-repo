#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-13
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int res = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            res += abs(seats[i] - students[i]);
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}