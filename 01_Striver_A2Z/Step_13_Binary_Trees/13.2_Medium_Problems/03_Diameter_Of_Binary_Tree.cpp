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
    // Helper for Brute Force: Standard Height calculation
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Helper for Optimal: Calculates height AND updates max diameter simultaneously
    int checkHeightForDiameter(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;

        // 1. Postorder: get heights of left and right subtrees
        int leftHeight = checkHeightForDiameter(root->left, maxi);
        int rightHeight = checkHeightForDiameter(root->right, maxi);

        // 2. The diameter passing through THIS node is leftHeight + rightHeight.
        // Update the global maximum if it's larger.
        maxi = max(maxi, leftHeight + rightHeight);

        // 3. Return the height of this subtree to the parent
        return 1 + max(leftHeight, rightHeight);
    }

public:
    // APPROACH 1: Brute Force (Top-Down)
    // Time Complexity: O(N^2) | Space Complexity: O(H)
    int diameterOfBinaryTreeBrute(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int currentDiameter = height(root->left) + height(root->right);

        // Recursively find the max diameter in left and right subtrees
        int leftDiameter = diameterOfBinaryTreeBrute(root->left);
        int rightDiameter = diameterOfBinaryTreeBrute(root->right);

        return max({currentDiameter, leftDiameter, rightDiameter});
    }

    // APPROACH 2: Optimal (Bottom-Up Postorder with Reference Variable)
    // Time Complexity: O(N) | Space Complexity: O(H)
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        checkHeightForDiameter(root, maxi);
        return maxi;
    }
};

int main()
{
    Solution obj;

    // Constructing a tree where the diameter passes through the root
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout << "Diameter of Tree 1 (Optimal): " << obj.diameterOfBinaryTree(root1) << "\n";
    // Expected: 3 (Path: 4 -> 2 -> 1 -> 3)

    return 0;
}