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
    // Record parent pointers for every node using BFS
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTrack)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left != nullptr)
            {
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

public:
    // OPTIMAL APPROACH: Parent Mapping + Radial BFS
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (root == nullptr)
            return {};

        // Step 1: Map each node to its parent so we can traverse upwards
        unordered_map<TreeNode *, TreeNode *> parentTrack;
        markParents(root, parentTrack);

        // Step 2: Radial BFS starting from the target node
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        q.push(target);
        visited[target] = true;
        int currLevel = 0;

        while (!q.empty())
        {
            int size = q.size();

            // Once we reach distance k, the queue holds all our answer nodes
            if (currLevel++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                // Move Left
                if (curr->left != nullptr && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                // Move Right
                if (curr->right != nullptr && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                // Move Up (Parent)
                if (parentTrack[curr] != nullptr && !visited[parentTrack[curr]])
                {
                    q.push(parentTrack[curr]);
                    visited[parentTrack[curr]] = true;
                }
            }
        }

        // Collect all nodes remaining in the queue
        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *target = root->left;
    int k = 2;

    vector<int> ans = obj.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target->val << ": ";
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";
    // Expected: 7 4 1

    return 0;
}