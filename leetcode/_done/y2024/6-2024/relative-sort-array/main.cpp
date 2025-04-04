#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-11
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < arr2.size(); i++)
        {
            umap[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b)
             { if(umap.find(a) == umap.end() && umap.find(b) == umap.end()){
                return a > b;
             } else if(umap.find(a) == umap.end()){
                return true;
             } else if(umap.find(b) == umap.end()){
                return true;
             } else { 
                return umap[a] < umap[b];
            } });
        return arr1;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}