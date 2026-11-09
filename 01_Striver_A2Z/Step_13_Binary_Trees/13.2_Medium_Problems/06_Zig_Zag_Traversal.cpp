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
    // APPROACH 1: Brute Force using STL reverse
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<vector<int>> zigzagLevelOrderBrute(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            // Reverse the array if the flag demands it
            if (!leftToRight)
            {
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
            leftToRight = !leftToRight; // Toggle the flag for the next level
        }

        return ans;
    }

    // APPROACH 2: Optimal using Smart Indexing
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            // Pre-allocate the vector with the exact size needed for this level
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Determine the correct index based on the current direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight; // Toggle the flag for the next level
        }

        return ans;
    }
};

void print2DVector(const vector<vector<int>> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
            if (j != vec[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]\n";
}

int main()
{
    Solution obj;

    // Constructing the tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Zig Zag Traversal: ";
    print2DVector(obj.zigzagLevelOrder(root));
    // Expected: [[3],[20,9],[15,7]]

    return 0;
}