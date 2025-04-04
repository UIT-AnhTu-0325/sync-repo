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

// daily-question&envId=2024-07-16
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    void solve(TreeNode *root, int startValue, int destValue, string &tmp,
               string &wayStart, string &wayEnd) {
        if (!root) return;

        if (root->val == startValue) wayStart = tmp;
        if (root->val == destValue) wayEnd = tmp;

        tmp.push_back('L');
        solve(root->left, startValue, destValue, tmp, wayStart, wayEnd);
        tmp.pop_back();

        tmp.push_back('R');
        solve(root->right, startValue, destValue, tmp, wayStart, wayEnd);
        tmp.pop_back();
    }

    string getDirections(TreeNode *root, int startValue, int destValue) {
        string wayStart, wayDest, tmp;
        solve(root, startValue, destValue, tmp, wayStart, wayDest);

        int idx = 0;
        while (idx < wayStart.length() && idx < wayDest.length() &&
               wayStart[idx] == wayDest[idx]) {
            idx++;
        }

        string res;
        for (int i = wayStart.length() - 1; i >= idx; i--) {
            res += 'U';
        }
        for (int i = idx; i < wayDest.length(); i++) {
            res += wayDest[i];
        }

        return res;
    }
};

int main() {
    TreeNode *root =
        new TreeNode(5, new TreeNode(1, new TreeNode(3), nullptr),
                     new TreeNode(2, new TreeNode(6), new TreeNode(4)));
    Solution *solution = new Solution();
    solution->getDirections(root, 3, 6);
    cout << "Hello world";
}