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
    bool flag = true;
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1)
            flag = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return flag;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}