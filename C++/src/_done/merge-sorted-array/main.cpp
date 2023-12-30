#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int l1 = nums1.size();
    int l2 = nums2.size();
    l1 = l1 - l2;

    int c1 = 0, c2 = 0;
    vector<int> res = vector<int>();

    while (c1 < l1 && c2 < l2)
    {
        if (nums1[c1] < nums2[c2])
        {
            res.push_back(nums1[c1]);
            c1++;
        }
        else
        {
            res.push_back(nums2[c2]);
            c2++;
        }
    }
    while (c1 < l1)
    {
        res.push_back(nums1[c1]);
        c1++;
    }
    while (c2 < l2)
    {
        res.push_back(nums2[c2]);
        c2++;
    }
    for(int i = 0; i< res.size(); i++)
    {
        nums1[i] = res[i];
    }
}

int main()
{
}