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
    // Helper for Right View
    // Prioritizes Root -> Right -> Left
    void recursionRight(TreeNode *root, int level, vector<int> &res)
    {
        if (root == nullptr)
            return;

        if (res.size() == level)
        {
            res.push_back(root->val);
        }

        recursionRight(root->right, level + 1, res);
        recursionRight(root->left, level + 1, res);
    }

    // Helper for Left View
    // Prioritizes Root -> Left -> Right
    void recursionLeft(TreeNode *root, int level, vector<int> &res)
    {
        if (root == nullptr)
            return;

        if (res.size() == level)
        {
            res.push_back(root->val);
        }

        recursionLeft(root->left, level + 1, res);
        recursionLeft(root->right, level + 1, res);
    }

public:
    // OPTIMAL APPROACH: DFS for Right View
    // Time Complexity: O(N) | Space Complexity: O(H) stack space
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        recursionRight(root, 0, res);
        return res;
    }

    // OPTIMAL APPROACH: DFS for Left View
    // Time Complexity: O(N) | Space Complexity: O(H) stack space
    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> res;
        recursionLeft(root, 0, res);
        return res;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //        \   \
    //         5   4
    //        /
    //       6
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(6);

    vector<int> rightView = obj.rightSideView(root);
    vector<int> leftView = obj.leftSideView(root);

    cout << "Right View: ";
    for (int val : rightView)
        cout << val << " ";
    cout << "\n";
    // Expected: 1 3 4 6

    cout << "Left View:  ";
    for (int val : leftView)
        cout << val << " ";
    cout << "\n";
    // Expected: 1 2 5 6

    return 0;
}