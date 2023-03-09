#include <iostream>
#include <algorithm>
#include <vector>
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

TreeNode *Create(vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = Create(nums, left, mid - 1);
    root->right = Create(nums, mid + 1, right);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return Create(nums, 0, nums.size() - 1);
}

int main()
{
}