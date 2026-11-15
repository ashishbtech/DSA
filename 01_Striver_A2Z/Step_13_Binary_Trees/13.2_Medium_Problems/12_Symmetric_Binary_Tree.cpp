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
    bool isSymmetricHelp(TreeNode *leftNode, TreeNode *rightNode)
    {
        // If both reach null at the same time, they are mirrored
        if (leftNode == nullptr && rightNode == nullptr)
        {
            return true;
        }

        // If only one is null, or if their values don't match, symmetry is broken
        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val)
        {
            return false;
        }

        // Check outer children (Left's Left with Right's Right)
        // AND inner children (Left's Right with Right's Left)
        return isSymmetricHelp(leftNode->left, rightNode->right) &&
               isSymmetricHelp(leftNode->right, rightNode->left);
    }

public:
    // OPTIMAL APPROACH: Simultaneous DFS
    // Time Complexity: O(N) | Space Complexity: O(H) stack space
    bool isSymmetric(TreeNode *root)
    {
        // An empty tree is symmetric by definition
        if (root == nullptr)
            return true;

        // Compare the left subtree against the right subtree
        return isSymmetricHelp(root->left, root->right);
    }
};

int main()
{
    Solution obj;

    // Constructing a Symmetric Tree:
    //         1
    //        / \
    //       2   2
    //      / \ / \
    //     3  4 4  3
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    // Constructing an Asymmetric Tree:
    //         1
    //        / \
    //       2   2
    //        \   \
    //         3   3
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    cout << "Tree 1 is Symmetric: " << (obj.isSymmetric(root1) ? "True" : "False") << "\n";
    // Expected: True

    cout << "Tree 2 is Symmetric: " << (obj.isSymmetric(root2) ? "True" : "False") << "\n";
    // Expected: False

    return 0;
}