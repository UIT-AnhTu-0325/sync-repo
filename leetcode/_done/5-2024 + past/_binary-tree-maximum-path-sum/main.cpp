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
public:
    int maxPath(TreeNode *root, int &crr)
    {
        if (root == nullptr)
            return 0;

        int left = max(0, maxPath(root->left, crr));
        int right = max(0, maxPath(root->right, crr));

        crr = max(crr, left + root->val + right);

        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        int mx = INT32_MIN;
        maxPath(root, mx);
        return mx;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}