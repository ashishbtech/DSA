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
    void postorderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        // 1. Left
        postorderHelper(root->left, ans);
        // 2. Right
        postorderHelper(root->right, ans);
        // 3. Root
        ans.push_back(root->val);
    }

public:
    // APPROACH 1: Recursive DFS
    // Time Complexity: O(N) | Space Complexity: O(H) auxiliary stack space
    vector<int> postorderRecursive(TreeNode *root)
    {
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }

    // APPROACH 2: Iterative Using 2 Stacks
    // Time Complexity: O(N) | Space Complexity: O(2N)
    vector<int> postorder2Stacks(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);

            // Push left first, then right, so right pops first in st1
            if (curr->left != nullptr)
                st1.push(curr->left);
            if (curr->right != nullptr)
                st1.push(curr->right);
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }

    // APPROACH 3: Iterative Using 1 Stack (True Optimal)
    // Time Complexity: O(2N) | Space Complexity: O(N)
    vector<int> postorder1Stack(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr != nullptr || !st.empty())
        {
            if (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left; // Dive deep left
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == nullptr)
                {
                    // No right child, process node and backtrack
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    // Check if we are returning from a right child
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    // Right child exists, explore it
                    curr = temp;
                }
            }
        }

        return ans;
    }

    // Main function called by LeetCode
    vector<int> postorderTraversal(TreeNode *root)
    {
        return postorder1Stack(root);
    }
};

int main()
{
    Solution obj;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}