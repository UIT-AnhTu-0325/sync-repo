#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    int tmp = 0;
    int clone = x;
    while (clone > 0)
    {
        tmp += clone % 10;
        tmp *= 10;
        clone /= 10;
    }
    tmp /= 10;
    return tmp == x;
}

int main()
{
    int x;
    cin >> x;
    cout << (isPalindrome(x) ? "true" : "false");
}