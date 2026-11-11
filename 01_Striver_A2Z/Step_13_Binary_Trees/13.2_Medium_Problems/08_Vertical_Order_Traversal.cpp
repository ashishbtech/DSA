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
    // OPTIMAL APPROACH: BFS with Nested Maps and Multiset
    // Time Complexity: O(N log N) (due to map/multiset insertions)
    // Space Complexity: O(N) (for the map and queue)
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // Data Structure: map< x, map< y, multiset<values> > >
        map<int, map<int, multiset<int>>> nodes;

        // Queue holds pairs of {Node, {x, y}}
        queue<pair<TreeNode *, pair<int, int>>> q;

        if (root == nullptr)
            return {};

        // Root is at coordinate (0, 0)
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode *curr = p.first;
            int x = p.second.first;  // Vertical line (Left/Right)
            int y = p.second.second; // Level (Depth)

            // Insert the node's value into our perfectly sorting data structure
            nodes[x][y].insert(curr->val);

            // If going left, x decreases, y increases
            if (curr->left != nullptr)
            {
                q.push({curr->left, {x - 1, y + 1}});
            }
            // If going right, x increases, y increases
            if (curr->right != nullptr)
            {
                q.push({curr->right, {x + 1, y + 1}});
            }
        }

        // Extract the fully sorted data into the final 2D answer array
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                // q.second is the multiset. Insert its elements into our column array.
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
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
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = obj.verticalTraversal(root);

    cout << "Vertical Order Traversal: ";
    print2DVector(result);
    // Expected Output: [[4],[2],[1,5,6],[3],[7]]

    return 0;
}