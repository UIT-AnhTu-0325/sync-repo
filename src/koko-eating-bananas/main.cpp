#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canEat(vector<int> &piles, int h, int speed)
{
    int time = 0;
    for (int pile : piles)
    {
        time += (pile - 1) / speed + 1;
        if (time > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (canEat(piles, h, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int n;
    cin >> n;
    vector<int> piles(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }
    int h;
    cin >> h;
    cout << minEatingSpeed(piles, h);
}