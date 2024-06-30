#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int dfs(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return res;
        int resLeft = dfs(root->left, res);
        int resRight = dfs(root->right, res);
        int left = 0, right = 0;

        if (root->left != nullptr && root->left->val == root->val)
            left = resLeft + 1;
        if (root->right != nullptr && root->right->val == root->val)
            right = resRight + 1;

        res = max(res, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}