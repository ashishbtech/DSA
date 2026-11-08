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
    // Helper for Brute Force: Preorder traversal saving null markers
    void preorderWithNulls(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            arr.push_back(INT_MIN); // Null marker
            return;
        }
        arr.push_back(root->val);
        preorderWithNulls(root->left, arr);
        preorderWithNulls(root->right, arr);
    }

public:
    // APPROACH 1: Brute Force (Store and Compare)
    // Time Complexity: O(N) | Space Complexity: O(N)
    bool isSameTreeBrute(TreeNode *p, TreeNode *q)
    {
        vector<int> arr1, arr2;
        preorderWithNulls(p, arr1);
        preorderWithNulls(q, arr2);

        return arr1 == arr2;
    }

    // APPROACH 2: Optimal Simultaneous DFS
    // Time Complexity: O(N) | Space Complexity: O(H) stack space
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (p == nullptr || q == nullptr || p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution obj;

    // Constructing Tree 1
    //       1
    //      / \
    //     2   3
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Constructing Tree 2 (Identical to Tree 1)
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    // Constructing Tree 3 (Different structure)
    //       1
    //      /
    //     2
    //      \
    //       3
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->left->right = new TreeNode(3);

    cout << "Tree 1 and Tree 2 are identical: "
         << (obj.isSameTree(root1, root2) ? "True" : "False") << "\n";
    // Expected: True

    cout << "Tree 1 and Tree 3 are identical: "
         << (obj.isSameTree(root1, root3) ? "True" : "False") << "\n";
    // Expected: False

    return 0;
}