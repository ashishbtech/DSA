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
    bool isLeaf(TreeNode *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }

    void addLeftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->left;
        while (curr != nullptr)
        {
            // If it's not a leaf, add it to the boundary
            if (!isLeaf(curr))
            {
                res.push_back(curr->val);
            }
            // Prioritize going left. If no left child exists, go right.
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;

        if (isLeaf(root))
        {
            res.push_back(root->val);
            return;
        }

        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }

    void addRightBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->right;
        vector<int> temp;

        while (curr != nullptr)
        {
            if (!isLeaf(curr))
            {
                temp.push_back(curr->val);
            }

            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }

public:
    // OPTIMAL APPROACH: Modular decomposition
    // Time Complexity: O(N) | Space Complexity: O(N) for result array
    vector<int> printBoundary(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        // 1. Add the root (if it's not a leaf itself)
        if (!isLeaf(root))
        {
            res.push_back(root->val);
        }

        // 2. Get the left boundary (excluding leaves)
        addLeftBoundary(root, res);

        // 3. Get all the leaves
        addLeaves(root, res);

        // 4. Get the right boundary in reverse (excluding leaves)
        addRightBoundary(root, res);

        return res;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   7
    //      / \   \
    //     3   4   8
    //        / \  /
    //       5   6 9
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    vector<int> boundary = obj.printBoundary(root);

    cout << "Boundary Traversal: ";
    for (int val : boundary)
    {
        cout << val << " ";
    }
    cout << "\n";
    // Expected: 1 2 3 5 6 9 8 7

    return 0;
}