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
private:
    int findLeftHeight(TreeNode *node)
    {
        int height = 0;
        while (node != nullptr)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode *node)
    {
        int height = 0;
        while (node != nullptr)
        {
            height++;
            node = node->right;
        }
        return height;
    }

public:
    // APPROACH 1: Brute Force (Standard DFS)
    // Time Complexity: O(N) | Space Complexity: O(log N)
    int countNodesBrute(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countNodesBrute(root->left) + countNodesBrute(root->right);
    }

    // APPROACH 2: Optimal (Leveraging Complete Binary Tree Property)
    // Time Complexity: O((log N)^2) | Space Complexity: O(log N)
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        // If extreme left and right heights match, it's a perfect binary tree: 2^h - 1
        if (lh == rh)
        {
            return (1 << lh) - 1;
        }

        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
    Solution obj;

    // Constructing a Complete Binary Tree:
    //         1
    //        / \
    //       2   3
    //      / \ /
    //     4  5 6
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Total Nodes (Brute):   " << obj.countNodesBrute(root) << "\n";
    cout << "Total Nodes (Optimal): " << obj.countNodes(root) << "\n";
    // Expected: 6

    return 0;
}