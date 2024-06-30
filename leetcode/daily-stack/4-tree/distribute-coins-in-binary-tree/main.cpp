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
    int calc(TreeNode *root, int &crr)
    {
        if (root == nullptr)
            return 0;
        int needLeft = calc(root->left, crr);
        int needRight = calc(root->right, crr);
        root->val -= needLeft;
        root->val -= needRight;
        crr += abs(needLeft);
        crr += abs(needRight);
        return 1 - root->val;
    }
    int distributeCoins(TreeNode *root)
    {
        int res = 0;
        calc(root, res);
        return res;
    }
};

int main()
{
    TreeNode *inp =
        new TreeNode(1,
                     new TreeNode(0, nullptr, new TreeNode(3)),
                     new TreeNode(0));
    Solution *solution = new Solution();
    solution->distributeCoins(inp);
    cout << "Hello world";
}