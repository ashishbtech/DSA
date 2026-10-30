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
    void preorderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        // 1. Root
        ans.push_back(root->val);
        // 2. Left
        preorderHelper(root->left, ans);
        // 3. Right
        preorderHelper(root->right, ans);
    }

public:
    // APPROACH 1: Recursive DFS
    // Time Complexity: O(N) | Space Complexity: O(H) auxiliary stack space
    vector<int> preorderRecursive(TreeNode *root)
    {
        vector<int> ans;
        preorderHelper(root, ans);
        return ans;
    }

    // APPROACH 2: Iterative Using Stack
    // Time Complexity: O(N) | Space Complexity: O(N) explicit stack space
    vector<int> preorderIterative(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            // 1. Root
            ans.push_back(curr->val);

            // 2. Push Right FIRST (so Left is popped first due to LIFO)
            if (curr->right != nullptr)
            {
                st.push(curr->right);
            }
            // 3. Push Left SECOND
            if (curr->left != nullptr)
            {
                st.push(curr->left);
            }
        }

        return ans;
    }

    // Main function called by LeetCode
    vector<int> preorderTraversal(TreeNode *root)
    {
        return preorderIterative(root);
    }
};

int main()
{
    Solution obj;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}