#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isBadVersion(int version)
{
    return version >= 16;
}
int firstBadVersion(int n)
{
    int left = 1, right = n, ans, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid) == false)
            left = mid + 1;
        else
        {
            ans = mid;
            if (mid == 1 || isBadVersion(mid - 1) == false)
            {
                return mid;
            }
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
}