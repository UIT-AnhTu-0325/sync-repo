#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-25
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
    int crrSum;
    int getSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return getSum(root->left) +
               root->val +
               getSum(root->right);
    }
    void bfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
        {
            bfs(root->left);
        }
        int tmp = root->val;
        root->val = crrSum;
        crrSum -= tmp;
        if (root->right != nullptr)
        {
            bfs(root->right);
        }
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        crrSum = getSum(root);
        bfs(root);
        return root;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}