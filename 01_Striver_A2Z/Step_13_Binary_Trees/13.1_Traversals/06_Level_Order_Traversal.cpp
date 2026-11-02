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
    // OPTIMAL APPROACH: Iterative BFS (Queue)
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Add left and right children to the queue for the NEXT level
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);

                level.push_back(node->val);
            }

            // Store the current level's nodes
            ans.push_back(level);
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

    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "Level Order Traversal: ";
    print2DVector(ans);
    // Expected: [[3],[9,20],[15,7]]

    return 0;
}