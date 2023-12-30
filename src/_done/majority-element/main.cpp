#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> u;
    for (int i = 0; i < nums.size(); i++)
    {
        u[nums[i]]++;
    }
    unordered_map<int, int>::iterator it;
    for (it = u.begin(); it != u.end(); it++)
    {
        if(it->second >= (nums.size()+1)/2)
        {
            return it->first;
        }
    }
    return 0;
}

int main()
{
}