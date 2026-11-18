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
    // OPTIMAL APPROACH: BFS with 0-based Normalized Indexing
    // Time Complexity: O(N) | Space Complexity: O(N)
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        long long maxWidth = 0;
        // Queue stores {Node, index}
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            // Minimum index on the current level (used to normalize and prevent overflow)
            long long minIdx = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                long long currIdx = q.front().second - minIdx;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = currIdx;
                if (i == size - 1)
                    last = currIdx;

                if (node->left != nullptr)
                {
                    q.push({node->left, currIdx * 2 + 1});
                }
                if (node->right != nullptr)
                {
                    q.push({node->right, currIdx * 2 + 2});
                }
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return (int)maxWidth;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //          1
    //        /   \
    //       3     2
    //      /       \
    //     5         9
    //    /         /
    //   6         7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    cout << "Maximum Width of Binary Tree: " << obj.widthOfBinaryTree(root) << "\n";
    // Expected: 7

    return 0;
}