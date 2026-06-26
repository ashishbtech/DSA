#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // OPTIMAL: 4-Pointer Boundary Shrinking
    // Time Complexity: O(N * M) | Space Complexity: O(N * M) for the answer array
    vector<int> spiralOrderOptimal(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        // Keep looping until the boundaries cross each other
        while (top <= bottom && left <= right)
        {

            // 1. Traverse Right (along the top boundary)
            for (int i = left; i <= right; i++)
            {
                ans.push_back(mat[top][i]);
            }
            top++; // Shrink the top boundary downwards

            // 2. Traverse Down (along the right boundary)
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--; // Shrink the right boundary inwards

            // 3. Traverse Left (along the bottom boundary)
            
            // If the matrix is a single row, skipping this check prints it backwards again.
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(mat[bottom][i]);
                }
                bottom--; // Shrink the bottom boundary upwards
            }

            // 4. Traverse Up (along the left boundary)
            
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(mat[i][left]);
                }
                left++; // Shrink the left boundary inwards
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    vector<int> ans = obj.spiralOrderOptimal(mat);

    cout << "Output: [ ";
    for (int x : ans)
        cout << x << " ";
    cout << "]\n";

    return 0;
}