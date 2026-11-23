#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL APPROACH: Direct Property Check
    // 1 = Preorder, 2 = Inorder, 3 = Postorder
    // Time Complexity: O(1) | Space Complexity: O(1)
    bool isPossible(int a, int b)
    {
        return (a == 2 || b == 2) && (a != b);
    }
};

int main()
{
    Solution obj;

    // 1 = Preorder, 2 = Inorder, 3 = Postorder
    cout << "Preorder (1) & Inorder (2):  " << (obj.isPossible(1, 2) ? "True" : "False") << "\n";
    // Expected: True

    cout << "Postorder (3) & Inorder (2): " << (obj.isPossible(3, 2) ? "True" : "False") << "\n";
    // Expected: True

    cout << "Preorder (1) & Postorder (3): " << (obj.isPossible(1, 3) ? "True" : "False") << "\n";
    // Expected: False

    cout << "Inorder (2) & Inorder (2):   " << (obj.isPossible(2, 2) ? "True" : "False") << "\n";
    // Expected: False

    return 0;
}