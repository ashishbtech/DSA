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
    bool getPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path)
    {
        if (root == nullptr)
            return false;

        path.push_back(root);
        if (root == target)
            return true;

        if (getPath(root->left, target, path) || getPath(root->right, target, path))
        {
            return true;
        }

        path.pop_back();
        return false;
    }

public:
    // APPROACH 1: Brute Force (Path Arrays)
    // Time Complexity: O(N) | Space Complexity: O(N)
    TreeNode *lowestCommonAncestorBrute(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> pathP, pathQ;

        getPath(root, p, pathP);
        getPath(root, q, pathQ);

        TreeNode *lca = nullptr;
        // Traverse both paths until they diverge
        for (int i = 0; i < min(pathP.size(), pathQ.size()); i++)
        {
            if (pathP[i] == pathQ[i])
            {
                lca = pathP[i]; // Keep updating the last matching node
            }
            else
            {
                break;
            }
        }

        return lca;
    }

    // APPROACH 2: Optimal Single-Pass DFS
    // Time Complexity: O(N) | Space Complexity: O(H) stack space
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base case: If we hit a dead end, or if we find either target node.
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        // Go look for p and q in the left and right subtrees
        TreeNode *leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightResult = lowestCommonAncestor(root->right, p, q);

        // If BOTH left and right returned a node, this current node is the LCA!
        if (leftResult != nullptr && rightResult != nullptr)
        {
            return root;
        }

        // Otherwise, pass up whichever side successfully found a node
        // (if both are null, it safely returns null).
        if (leftResult != nullptr)
        {
            return leftResult;
        }
        else
        {
            return rightResult;
        }
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;

    TreeNode *lca = obj.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << "\n";
    // Expected: 5

    return 0;
}