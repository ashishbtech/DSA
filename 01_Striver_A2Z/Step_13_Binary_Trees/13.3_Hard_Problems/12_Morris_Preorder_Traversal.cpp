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
    // OPTIMAL APPROACH: Morris Preorder Traversal (Threaded Binary Tree)
    // Time Complexity: O(N) amortized | Space Complexity: O(1) auxiliary
    vector<int> getPreorder(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            // Case 1: No left child -> record current node and move right
            if (curr->left == nullptr)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Case 2: Find the rightmost node in the left subtree (inorder predecessor)
                TreeNode *prev = curr->left;
                while (prev->right != nullptr && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == nullptr)
                {
                    // First visit: create thread, record root (Preorder), and move left
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    // Second visit: left subtree is done -> remove thread and move right
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    //          \
    //           6
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> result = obj.getPreorder(root);

    cout << "Morris Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << "\n";
    // Expected: 1 2 4 5 6 3

    return 0;
}