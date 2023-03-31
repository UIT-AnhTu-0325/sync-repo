#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string builder = "";

bool isCanOpen(int input)
{
    int count = 0;
    for (int i = 0; i < builder.length(); i++)
    {
        if (builder[i] == '(')
        {
            count++;
        }
    }
    return count < input;
}

bool isCanClose(int input)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < builder.length(); i++)
    {
        if (builder[i] == '(')
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    return count1 > count2;
}

void res(int input, int n, vector<string> &r)
{
    if (n >= 0)
    {
        if (isCanOpen(input))
        {
            builder.push_back('(');
            res(input, n - 1, r);
            builder.pop_back();
        }

        if (isCanClose(input))
        {
            builder.push_back(')');
            res(input, n, r);
            if (builder.length() == input * 2)
            {
                r.push_back(builder);
            }
            builder.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> r;
    res(n, n, r);
    return r;
}

int main()
{
    int input;
    cin >> input;
    vector<string> res = generateParenthesis(input);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}