#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
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
    TreeNode * rootCop;
public:
    TreeNode *invertTree(TreeNode *root)
    {
        rootCop = doCopy(root);
        return rootCop;
    }
    TreeNode *doCopy(TreeNode *src){
        if(src == nullptr) return nullptr;
        TreeNode* des = new TreeNode(src->val);
        des->left = doCopy(src->right);
        des->right = doCopy(src->left);
        return des;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}