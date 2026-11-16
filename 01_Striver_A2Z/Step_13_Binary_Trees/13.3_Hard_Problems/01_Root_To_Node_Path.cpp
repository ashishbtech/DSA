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
    bool getPath(TreeNode *root, vector<int> &path, int target)
    {
        // Base case: Dead end
        if (root == nullptr)
            return false;

        // 1. Add current node to the path
        path.push_back(root->val);

        // 2. If we found the target, we are done! Return true immediately.
        if (root->val == target)
            return true;

        // 3. Dive Left and Right. If either returns true, the path is confirmed.
        if (getPath(root->left, path, target) || getPath(root->right, path, target))
        {
            return true;
        }

        // 4. Backtrack: If we reach here, this node is a dead end.
        // Pop it off the path and return false to the parent.
        path.pop_back();
        return false;
    }

public:
    // OPTIMAL APPROACH: DFS with Backtracking
    // Time Complexity: O(N) | Space Complexity: O(H) stack space
    vector<int> solve(TreeNode *root, int target)
    {
        vector<int> path;
        if (root == nullptr)
            return path;

        getPath(root, path, target);
        return path;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    //        /
    //       7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    int target = 7;
    vector<int> path = obj.solve(root, target);

    cout << "Path to node " << target << ": ";
    for (int val : path)
    {
        cout << val << " ";
    }
    cout << "\n";
    // Expected: 1 2 5 7

    return 0;
}