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
    int maxPathDown(TreeNode *node, int &maxi)
    {
        if (node == nullptr)
            return 0;

        // 1. Postorder: get max path sums of left and right subtrees.

        int leftSum = max(0, maxPathDown(node->left, maxi));
        int rightSum = max(0, maxPathDown(node->right, maxi));

        // 2. The max path sum passing through THIS node as the peak.
        // Update the global maximum if it's larger.
        maxi = max(maxi, node->val + leftSum + rightSum);

        // 3. Return the maximum linear path passing through this node to the parent
        return node->val + max(leftSum, rightSum);
    }

public:
    // OPTIMAL APPROACH: Bottom-Up Postorder with Reference Variable
    // Time Complexity: O(N) | Space Complexity: O(H)
    int maxPathSum(TreeNode *root)
    {

        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};

int main()
{
    Solution obj;

    // Constructing a tree with negative values:
    //       -10
    //       /  \
    //      9   20
    //         /  \
    //        15   7
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Path Sum: " << obj.maxPathSum(root) << "\n";
    // Expected: 42 (Path: 15 -> 20 -> 7)

    return 0;
}