#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class MinStack
{
public:
    int arr[10004];
    int minn[10004];
    int indx = -1;
    MinStack()
    {
    }

    void push(int val)
    {
        this->indx++;
        this->arr[indx] = val;
        if (indx == 0)
        {
            minn[indx] = val;
        }
        else
        {
            minn[indx] = min(minn[indx - 1], val);
        }
    }

    void pop()
    {
        this->indx--;
    }

    int top()
    {
        return this->arr[indx];
    }

    int getMin()
    {
        return this->minn[indx];
    }
};

int main()
{
    MinStack *m = new MinStack();
    int res = m->top();
    cout << res;
}