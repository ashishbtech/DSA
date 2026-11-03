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
public:
    // OPTIMAL APPROACH: One Stack State Machine
    // Time Complexity: O(3N) ~ O(N) | Space Complexity: O(N)
    vector<vector<int>> getTreeTraversal(TreeNode *root)
    {
        vector<int> pre, in, post;
        if (root == nullptr)
            return {pre, in, post};

        // Stack holds pairs of {Node, State}
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            // STATE 1: Preorder
            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                // Upgrade state and push back
                it.second = 2;
                st.push(it);

                // Dive Left
                if (it.first->left != nullptr)
                {
                    st.push({it.first->left, 1});
                }
            }
            // STATE 2: Inorder
            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                // Upgrade state and push back
                it.second = 3;
                st.push(it);

                // Dive Right
                if (it.first->right != nullptr)
                {
                    st.push({it.first->right, 1});
                }
            }
            // STATE 3: Postorder
            else
            {
                post.push_back(it.first->val);
                // We do NOT push it back to the stack. Let it remain popped.
            }
        }

        return {pre, in, post};
    }
};

// Helper function to print the 2D vector
void printTraversals(const vector<vector<int>> &traversals)
{
    cout << "Preorder:  ";
    for (int val : traversals[0])
        cout << val << " ";
    cout << "\nInorder:   ";
    for (int val : traversals[1])
        cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : traversals[2])
        cout << val << " ";
    cout << "\n";
}

int main()
{
    Solution obj;

    // Constructing the tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> traversals = obj.getTreeTraversal(root);

    printTraversals(traversals);
    // Expected Output:
    // Preorder:  1 2 4 5 3
    // Inorder:   4 2 5 1 3
    // Postorder: 4 5 2 3 1

    return 0;
}