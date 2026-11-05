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
    // Helper for Brute Force
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Helper for Optimal Approach
    int checkHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        // 1. Check Left Subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)
            return -1;

        // 2. Check Right Subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)
            return -1;

        // 3. Process Current Node
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

public:
    // APPROACH 1: Brute Force (Top-Down)
    // Time Complexity: O(N^2) | Space Complexity: O(H)
    bool isBalancedBrute(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Check current node, then check left and right subtrees
        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return isBalancedBrute(root->left) && isBalancedBrute(root->right);
    }

    // APPROACH 2: Optimal (Bottom-Up DFS)
    // Time Complexity: O(N) | Space Complexity: O(H)
    bool isBalanced(TreeNode *root)
    {
        // If checkHeight returns -1, it's unbalanced. Otherwise, it's balanced.
        return checkHeight(root) != -1;
    }
};

int main()
{
    Solution obj;

    // Constructing a Balanced Tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Tree 1 is Balanced: " << (obj.isBalanced(root1) ? "True" : "False") << "\n";
    // Expected: True

    // Constructing an Unbalanced Tree:
    //         1
    //        / \
    //       2   2
    //      / \
    //     3   3
    //    / \
    //   4   4
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Tree 2 is Balanced: " << (obj.isBalanced(root2) ? "True" : "False") << "\n";
    // Expected: False

    return 0;
}