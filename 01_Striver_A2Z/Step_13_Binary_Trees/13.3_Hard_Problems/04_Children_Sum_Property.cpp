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
    // Helper
    void incrementSubtree(TreeNode *node, int diff)
    {
        if (node->left != nullptr)
        {
            node->left->val += diff;
            incrementSubtree(node->left, diff);
        }
        else if (node->right != nullptr)
        {
            node->right->val += diff;
            incrementSubtree(node->right, diff);
        }
    }

public:
    // Time Complexity: O(N) | Space Complexity: O(H)
    bool isSumProperty(TreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }

        int childSum = 0;
        if (root->left != nullptr)
            childSum += root->left->val;
        if (root->right != nullptr)
            childSum += root->right->val;

        return (root->val == childSum) &&
               isSumProperty(root->left) &&
               isSumProperty(root->right);
    }

    // APPROACH 1: Brute Force (Postorder + Downward Increment)
    // Time Complexity: O(N^2) | Space Complexity: O(H)
    void changeTreeBrute(TreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return;
        }

        changeTreeBrute(root->left);
        changeTreeBrute(root->right);

        int childSum = 0;
        if (root->left != nullptr)
            childSum += root->left->val;
        if (root->right != nullptr)
            childSum += root->right->val;

        int diff = childSum - root->val;
        if (diff > 0)
        {
            root->val += diff;
        }
        else if (diff < 0)
        {
            incrementSubtree(root, -diff);
        }
    }

    // APPROACH 2: Optimal (Top-Down Push + Bottom-Up Sum)
    // Time Complexity: O(N) | Space Complexity: O(H)
    void changeTree(TreeNode *root)
    {
        if (root == nullptr)
            return;

        // 1. Going Down: compare current node with sum of its children
        int childSum = 0;
        if (root->left != nullptr)
            childSum += root->left->val;
        if (root->right != nullptr)
            childSum += root->right->val;

        if (childSum >= root->val)
        {
            root->val = childSum;
        }
        else
        {
            // Push root's value down so we never need to decrement on the way back up
            if (root->left != nullptr)
                root->left->val = root->val;
            if (root->right != nullptr)
                root->right->val = root->val;
        }

        // 2. Recurse on left and right subtrees
        changeTree(root->left);
        changeTree(root->right);

        // 3. Coming Back Up: update current node (if non-leaf) to the finalized sum
        int total = 0;
        if (root->left != nullptr)
            total += root->left->val;
        if (root->right != nullptr)
            total += root->right->val;

        if (root->left != nullptr || root->right != nullptr)
        {
            root->val = total;
        }
    }
};

void printInorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    Solution obj;

    // Constructing the tree:
    //          50
    //         /  \
    //        7    2
    //       / \  / \
    //      3   5 1  30
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    cout << "Before conversion (Valid? " << (obj.isSumProperty(root) ? "True" : "False") << "): ";
    printInorder(root);
    cout << "\n";

    obj.changeTree(root);

    cout << "After conversion  (Valid? " << (obj.isSumProperty(root) ? "True" : "False") << "): ";
    printInorder(root);
    cout << "\n";
    // Expected ; 50 100 50 200 50 100 50

    return 0;
}