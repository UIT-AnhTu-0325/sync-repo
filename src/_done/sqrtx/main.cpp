#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long mySqrt(long long x)
{
    long long i = 0;
    while (i * i <= x)
    {
        i++;
    }
    i -= 1;
    return i;
}

int main()
{
    long long x;
    cin >> x;
    cout << mySqrt(x);
}