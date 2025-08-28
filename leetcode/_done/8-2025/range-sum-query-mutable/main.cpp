#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class NumArray
{
private:
    int n;
    vector<int> tree;
    vector<int> nums; // keep original values

public:
    NumArray(vector<int> &nums)
    {
        this->n = nums.size();
        this->nums = nums;            // copy nums
        tree = vector<int>(n + 1, 0); // BIT is 1-based
        for (int i = 0; i < n; i++)
        {
            add(i + 1, nums[i]); // build BIT
        }
    }

    void update(int index, int val)
    {
        int diff = val - nums[index]; // compute change
        nums[index] = val;            // update stored value
        add(index + 1, diff);         // apply change to BIT
    }

    int sumRange(int left, int right)
    {
        return query(right + 1) - query(left);
    }

private:
    void add(int i, int delta)
    {
        while (i <= n)
        {
            tree[i] += delta;
            i += i & -i; // move to parent
        }
    }

    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            i -= i & -i; // move to ancestor
        }
        return sum;
    }
};

int main()
{
}