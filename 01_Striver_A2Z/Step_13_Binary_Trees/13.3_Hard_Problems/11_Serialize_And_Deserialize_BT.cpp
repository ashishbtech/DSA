#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
private:
    void serializeDFSHelper(TreeNode *root, string &data)
    {
        if (root == nullptr)
        {
            data += "#,";
            return;
        }
        data += to_string(root->val) + ",";
        serializeDFSHelper(root->left, data);
        serializeDFSHelper(root->right, data);
    }

    TreeNode *deserializeDFSHelper(stringstream &ss)
    {
        string token;
        if (!getline(ss, token, ',') || token == "#")
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(token));
        root->left = deserializeDFSHelper(ss);
        root->right = deserializeDFSHelper(ss);
        return root;
    }

public:
    // APPROACH 1: Preorder DFS
    // Time Complexity: O(N) | Space Complexity: O(N)
    string serializeDFS(TreeNode *root)
    {
        string data = "";
        serializeDFSHelper(root, data);
        return data;
    }

    TreeNode *deserializeDFS(string data)
    {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        return deserializeDFSHelper(ss);
    }

    // APPROACH 2: Level Order BFS (Striver's Optimal Standard)
    // Time Complexity: O(N) | Space Complexity: O(N)
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        string data = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == nullptr)
            {
                data += "#,";
            }
            else
            {
                data += to_string(curr->val) + ",";

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return data;
    }

    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        stringstream ss(data);
        string token;

        getline(ss, token, ',');
        TreeNode *root = new TreeNode(stoi(token));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            getline(ss, token, ',');
            if (token != "#")
            {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }

            getline(ss, token, ',');
            if (token != "#")
            {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }

        return root;
    }
};

void printInorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    Codec obj;

    // Constructing the tree:
    //         1
    //        / \
    //       2   13
    //          /  \
    //         4    5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string encoded = obj.serialize(root);
    cout << "Serialized (BFS):   " << encoded << "\n";
    // Expected: 1,2,13,#,#,4,5,#,#,#,#,

    TreeNode *decoded = obj.deserialize(encoded);
    cout << "Deserialized Inorder: ";
    printInorder(decoded);
    cout << "\n";
    // Expected: 2 1 4 13 5

    return 0;
}