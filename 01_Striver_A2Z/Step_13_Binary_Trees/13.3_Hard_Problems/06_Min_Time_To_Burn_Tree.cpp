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
    TreeNode *bfsToMapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTrack, int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *targetNode = nullptr;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->val == start)
            {
                targetNode = curr;
            }
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

        return targetNode;
    }

    int findMaxDistance(unordered_map<TreeNode *, TreeNode *> &parentTrack, TreeNode *target)
    {
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited;

        q.push(target);
        visited[target] = true;
        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool burnedAny = false;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left != nullptr && !visited[curr->left])
                {
                    burnedAny = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right != nullptr && !visited[curr->right])
                {
                    burnedAny = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parentTrack[curr] != nullptr && !visited[parentTrack[curr]])
                {
                    burnedAny = true;
                    visited[parentTrack[curr]] = true;
                    q.push(parentTrack[curr]);
                }
            }

            if (burnedAny)
                time++;
        }

        return time;
    }

public:
    // OPTIMAL APPROACH: Parent Mapping + Radial BFS
    // Time Complexity: O(N) | Space Complexity: O(N)
    int timeToBurnTree(TreeNode *root, int start)
    {
        if (root == nullptr)
            return 0;

        unordered_map<TreeNode *, TreeNode *> parentTrack;
        TreeNode *target = bfsToMapParents(root, parentTrack, start);

        if (target == nullptr)
            return 0;
        return findMaxDistance(parentTrack, target);
    }
};

int main()
{
    Solution obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   6
    //      \
    //       7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(7);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int start = 2;
    cout << "Minimum time to burn tree from node " << start << ": "
         << obj.timeToBurnTree(root, start) << "\n";
    // Expected: 3

    return 0;
}