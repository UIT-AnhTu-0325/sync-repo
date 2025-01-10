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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            vector<int> res = vector<int>{0};
            return res;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> leaves;

        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1)
                leaves.push_back(i);
        }

        int calc = n;

        while (calc > 2)
        {
            vector<int> newLeaves;

            calc -= leaves.size();
            for (int i = 0; i < leaves.size(); i++)
            {
                int neighbor = graph[leaves[i]][0];
                vector<int>::iterator item = find(graph[neighbor].begin(), graph[neighbor].end(), leaves[i]);
                if (item != graph[neighbor].end())
                {
                    graph[neighbor].erase(item);
                }
                if (graph[neighbor].size() == 1)
                {
                    newLeaves.push_back(neighbor);
                }
            }

            leaves = newLeaves;
        }

        return leaves;
    }
};
int main()
{
    Solution *solution = new Solution();
    vector<vector<int>> inp = {{0, 1}, {0, 2}};

    solution->findMinHeightTrees(3, inp);
    cout << "Hello world";
}

// Approach
// i) Create an adjacency list
// ii) Traverse the tree to identify the leaf nodes. Leaf nodes are nodes with only one adjacent node.
// iii) Remove the leaf nodes from the tree iteratively until only one or two nodes are left. This process involves removing nodes that become leaf nodes after each iteration.
// iv) After trimming, the remaining node(s) will be the root(s) of the MHTs. If there is only one remaining node, it will be the root of the single MHT. If there are two remaining nodes, they will be the roots of the MHTs.

// Concept:
// The root of the minimum height tree (MHT), also known as the "center of gravity," can consist of more than two nodes, depending on the tree's structure and the diameter.

// Case I :
// Odd Diameter:
// -> If the diameter of the tree is odd, the center of gravity will be a single node.
// -> This single node is the deepest node along the longest path in the tree.

// Case II :
// Even Diameter:
// -> If the diameter of the tree is even, the center of gravity will consist of two adjacent nodes.
// -> These two nodes are the midpoints of the longest path(s) in the tree.
// -> In this case, the center of gravity represents the midpoint(s) of the longest path(s).
