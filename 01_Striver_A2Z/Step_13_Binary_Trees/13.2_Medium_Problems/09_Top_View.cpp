#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // OPTIMAL APPROACH: BFS (Level Order) with a Map
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        // Map to store the first node's value at each vertical line (x-coordinate)
        // map<line, node->val>
        map<int, int> mpp;

        // Queue stores {Node, line}
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int line = it.second;

            // If this vertical line hasn't been seen yet, this is the top-most node!
            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->val;
            }

            // Standard BFS: push children with their respective vertical lines
            if (node->left != nullptr)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != nullptr)
            {
                q.push({node->right, line + 1});
            }
        }

        // The map is automatically sorted by the vertical lines (keys) from negative to positive
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = obj.topView(root);

    cout << "Top View Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << "\n";
    // Expected Output: 4 2 1 3 7

    return 0;
}