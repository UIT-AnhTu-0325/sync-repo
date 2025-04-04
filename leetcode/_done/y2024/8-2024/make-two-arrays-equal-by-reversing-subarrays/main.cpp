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

// daily-question 2024-08-03
class Solution {
   public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> umap1, umap2;
        for (int t1 : target) {
            umap1[t1]++;
        }
        for (int t2 : arr) {
            umap2[t2]++;
        }
        for (pair<int, int> p1 : umap1) {
            if (umap2[p1.first] != p1.second) return false;
        }

        for (pair<int, int> p2 : umap2) {
            if (umap1[p2.first] != p2.second) return false;
        }
        return true;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}