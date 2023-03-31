#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double myRealPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    double res = myRealPow(x, n / 2);
    if (n % 2 == 0)
    {
        return res * res;
    }
    else
    {
        return res * res * x;
    }
}

double myPow(double x, int n)
{
    double res = myRealPow(x, abs(n));
    return n > 0 ? res : 1.0 / res;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
}