#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int i = 19;
    int *a = &i;
    int **b = &a;

    cout << i << '\t' << &i << endl
         << a << '\t' << *a << '\t' << &a << endl
         << b << '\t' << *b << '\t' << **b << endl;
}