#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    
    int k = 1;
    bool isSecond = false;
    
    vector<int> res = vector<int>();
    res.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            k++;
            res.push_back(nums[i]);
            isSecond = false;
        }
        else if (nums[i] == nums[i - 1] && !isSecond)
        {
            k++;
            res.push_back(nums[i]);
            isSecond = true;
        }
        else
        {
            continue;
        }
    }
    for(int i = 0; i < k; i ++)
    {
        nums[i] = res[i];
    }
    return k;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr = vector<int>();
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int k = removeDuplicates(arr);
    
    cout << k << endl; 

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

}