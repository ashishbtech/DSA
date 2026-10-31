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
    void inorderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        // 1. Left
        inorderHelper(root->left, ans);
        // 2. Root
        ans.push_back(root->val);
        // 3. Right
        inorderHelper(root->right, ans);
    }

public:
    // APPROACH 1: Recursive DFS
    // Time Complexity: O(N) | Space Complexity: O(H) auxiliary stack space
    vector<int> inorderRecursive(TreeNode *root)
    {
        vector<int> ans;
        inorderHelper(root, ans);
        return ans;
    }

    // APPROACH 2: Iterative Using Stack
    // Time Complexity: O(N) | Space Complexity: O(N) explicit stack space
    vector<int> inorderIterative(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (true)
        {
            if (curr != nullptr)
            {
                // Dive as deep left as possible, saving nodes to stack
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                // If we hit null, and stack is empty, we are completely done
                if (st.empty())
                    break;

                // Backtrack: pop the top node, process it, and move right
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);

                curr = curr->right;
            }
        }

        return ans;
    }

    // Main function called by LeetCode
    vector<int> inorderTraversal(TreeNode *root)
    {

        return inorderIterative(root);
    }
};

int main()
{
    Solution obj;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}