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
    // APPROACH 1: Recursive DFS (Optimal)
    // Time Complexity: O(N) | Space Complexity: O(H) auxiliary stack
    int maxDepthRecursive(TreeNode *root)
    {

        if (root == nullptr)
        {
            return 0;
        }

        // Postorder traversal: get heights of left and right subtrees
        int leftHeight = maxDepthRecursive(root->left);
        int rightHeight = maxDepthRecursive(root->right);

        // Add 1 for the current node and take the max of both sides
        return 1 + max(leftHeight, rightHeight);
    }

    // APPROACH 2: Iterative BFS (Level Order)
    // Time Complexity: O(N) | Space Complexity: O(N) queue space
    int maxDepthIterative(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int size = q.size();
            depth++;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }

        return depth;
    }

    // Main function called by LeetCode
    int maxDepth(TreeNode *root)
    {
        return maxDepthRecursive(root);
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Max Depth (Recursive): " << obj.maxDepth(root) << "\n";
    cout << "Max Depth (Iterative): " << obj.maxDepthIterative(root) << "\n";

    return 0;
}