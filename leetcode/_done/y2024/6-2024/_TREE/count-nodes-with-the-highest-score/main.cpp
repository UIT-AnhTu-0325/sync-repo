#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    struct TreeNodeCus
    {
        long long val;
        vector<TreeNodeCus *> children;
        TreeNodeCus(long long v) : val(v) {}
    };

    long long countHighestScoreNodes(vector<int> &parents)
    {
        long long n = parents.size();
        vector<TreeNodeCus *> nodes(n);
        for (long long i = 0; i < n; ++i)
        {
            nodes[i] = new TreeNodeCus(i);
        }
        TreeNodeCus *root = nullptr;
        for (long long i = 1; i < n; ++i)
        {
            nodes[parents[i]]->children.push_back(nodes[i]);
        }
        root = nodes[0];

        unordered_map<long long, long long> subtreeSizes;
        long long maxScore = 0;
        long long count = 0;

        function<long long(TreeNodeCus *)> dfs = [&](TreeNodeCus *node)
        {
            long long size = 1;
            long long score = 1;
            for (TreeNodeCus *child : node->children)
            {
                long long childSize = dfs(child);
                size += childSize;
                score *= childSize;
            }
            long long remainingSize = n - size;
            if (remainingSize > 0)
            {
                score *= remainingSize;
            }
            subtreeSizes[node->val] = size;
            if (score > maxScore)
            {
                maxScore = score;
                count = 1;
            }
            else if (score == maxScore)
            {
                count++;
            }
            return size;
        };

        dfs(root);
        return count;
    }
};

int main()
{
    vector<int> inp = {-1, 2, 0};
    Solution *solution = new Solution();
    solution->countHighestScoreNodes(inp);
    cout << "Hello world";
}