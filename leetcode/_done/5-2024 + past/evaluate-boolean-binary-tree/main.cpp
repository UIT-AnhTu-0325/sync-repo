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
    bool evaluateTree(TreeNode *root)
    {
        if(root->val == 0) return false;
        if(root->val == 1) return true;
        if(root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}