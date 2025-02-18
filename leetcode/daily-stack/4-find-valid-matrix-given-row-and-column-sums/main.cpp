#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question 2024-07-20
class Solution {
  public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
      int m = rowSum.size();
      int n = colSum.size();

      int i = 0, j =0;
      vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n, 0));

      while(i < m && j < n){
        int value = min(rowSum[i], colSum[j]);
        res[i][j] = value;
        rowSum[i] -= value;
        colSum[j] -= value;

        if(rowSum[i] == 0) i++; 
        if(colSum[j] == 0) j++;
      }

      return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> rowSum = vector<int>{3, 8};
    vector<int> colSum = vector<int>{4, 7};
    solution->restoreMatrix(rowSum, colSum);
    cout << "Hello world";
}