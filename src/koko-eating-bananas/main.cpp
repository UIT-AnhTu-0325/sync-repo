#include <iostream>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    return 10;
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