#include <bits/stdc++.h>
using namespace std;

// structure for the tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
private:
    // Helper function for Recursive Approach
    node *buildTreeRecursive(vector<int> &vec, int i, int n)
    {
        // Base case: If index is out of bounds, return NULL
        if (i >= n)
        {
            return NULL;
        }

        // Create the current node
        node *root = new node(vec[i]);

        // Recursively build the left and right subtrees
        root->left = buildTreeRecursive(vec, 2 * i + 1, n);
        root->right = buildTreeRecursive(vec, 2 * i + 2, n);

        return root;
    }

public:
    // OPTIMAL APPROACH: Recursion using 2*i+1 and 2*i+2 logic
    // Time Complexity: O(N) | Space Complexity: O(log N) stack space
    void create_tree(node *root0, vector<int> &vec)
    {
        int n = vec.size();
        if (n == 0)
            return;

        root0->left = buildTreeRecursive(vec, 1, n);
        root0->right = buildTreeRecursive(vec, 2, n);
    }
};

// Helper function to print Level Order
void printLevelOrder(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << "\n";
}

int main()
{
    Solution obj;

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    node *root0 = new node(vec[0]);

    obj.create_tree(root0, vec);

    cout << "Tree created. Level Order Traversal should match the input array:\n";
    printLevelOrder(root0);

    return 0;
}