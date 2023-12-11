#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int min_price = prices[0];
    int maxprof = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            maxprof += (prices[i] - prices[i - 1]);
        }
    }

    return maxprof;
}

int main()
{
}