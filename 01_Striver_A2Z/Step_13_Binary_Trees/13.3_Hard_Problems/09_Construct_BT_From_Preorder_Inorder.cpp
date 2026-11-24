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
    TreeNode *buildBrute(vector<int> &preorder, int preStart, int preEnd,
                         vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = inStart;
        while (inRoot <= inEnd && inorder[inRoot] != root->val)
        {
            inRoot++;
        }

        int numsLeft = inRoot - inStart;

        root->left = buildBrute(preorder, preStart + 1, preStart + numsLeft,
                                inorder, inStart, inRoot - 1);
        root->right = buildBrute(preorder, preStart + numsLeft + 1, preEnd,
                                 inorder, inRoot + 1, inEnd);

        return root;
    }

    TreeNode *buildOptimal(vector<int> &preorder, int preStart, int preEnd,
                           vector<int> &inorder, int inStart, int inEnd,
                           unordered_map<int, int> &inMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildOptimal(preorder, preStart + 1, preStart + numsLeft,
                                  inorder, inStart, inRoot - 1, inMap);
        root->right = buildOptimal(preorder, preStart + numsLeft + 1, preEnd,
                                   inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    // APPROACH 1: Brute Force (Linear Search)
    // Time Complexity: O(N^2) | Space Complexity: O(H)
    TreeNode *buildTreeBrute(vector<int> &preorder, vector<int> &inorder)
    {
        return buildBrute(preorder, 0, preorder.size() - 1,
                          inorder, 0, inorder.size() - 1);
    }

    // APPROACH 2: Optimal (Hash Map for Inorder Indices)
    // Time Complexity: O(N) | Space Complexity: O(N)
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        return buildOptimal(preorder, 0, preorder.size() - 1,
                            inorder, 0, inorder.size() - 1, inMap);
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

void printPreorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    Solution obj;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Constructed Tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode *root = obj.buildTree(preorder, inorder);

    cout << "Reconstructed Preorder: ";
    printPreorder(root);
    cout << "\n";
    // Expected: 3 9 20 15 7

    cout << "Reconstructed Inorder:  ";
    printInorder(root);
    cout << "\n";
    // Expected: 9 3 15 20 7

    return 0;
}