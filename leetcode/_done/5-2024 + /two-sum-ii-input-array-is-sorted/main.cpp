#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0;
    int r = numbers.size() - 1;

    while (numbers[l] + numbers[r] != target)
    {
        if (numbers[l] + numbers[r] > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    vector<int> result{l + 1, r + 1};

    return result;
}

int main()
{
}