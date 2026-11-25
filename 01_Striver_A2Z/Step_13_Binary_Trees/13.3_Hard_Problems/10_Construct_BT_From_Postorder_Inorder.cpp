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
    TreeNode *buildBrute(vector<int> &inorder, int inStart, int inEnd,
                         vector<int> &postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inRoot = inStart;
        while (inRoot <= inEnd && inorder[inRoot] != root->val)
        {
            inRoot++;
        }

        int numsLeft = inRoot - inStart;

        root->left = buildBrute(inorder, inStart, inRoot - 1,
                                postorder, postStart, postStart + numsLeft - 1);
        root->right = buildBrute(inorder, inRoot + 1, inEnd,
                                 postorder, postStart + numsLeft, postEnd - 1);

        return root;
    }

    TreeNode *buildOptimal(vector<int> &inorder, int inStart, int inEnd,
                           vector<int> &postorder, int postStart, int postEnd,
                           unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildOptimal(inorder, inStart, inRoot - 1,
                                  postorder, postStart, postStart + numsLeft - 1, inMap);
        root->right = buildOptimal(inorder, inRoot + 1, inEnd,
                                   postorder, postStart + numsLeft, postEnd - 1, inMap);

        return root;
    }

public:
    // APPROACH 1: Brute Force (Linear Search)
    // Time Complexity: O(N^2) | Space Complexity: O(H)
    TreeNode *buildTreeBrute(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return nullptr;

        return buildBrute(inorder, 0, inorder.size() - 1,
                          postorder, 0, postorder.size() - 1);
    }

    // APPROACH 2: Optimal (Hash Map for Inorder Indices)
    // Time Complexity: O(N) | Space Complexity: O(N)
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return nullptr;

        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        return buildOptimal(inorder, 0, inorder.size() - 1,
                            postorder, 0, postorder.size() - 1, inMap);
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

void printPostorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main()
{
    Solution obj;

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Constructed Tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode *root = obj.buildTree(inorder, postorder);

    cout << "Reconstructed Inorder:   ";
    printInorder(root);
    cout << "\n";
    // Expected: 9 3 15 20 7

    cout << "Reconstructed Postorder: ";
    printPostorder(root);
    cout << "\n";
    // Expected: 9 15 7 20 3

    return 0;
}