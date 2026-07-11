#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Traverse every cell
    // Time Complexity: O(N * M) | Space Complexity: O(1)
    bool searchElementBrute(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }

    // 2. BETTER: Binary Search on every single row
    // Time Complexity: O(N * log M) | Space Complexity: O(1)
    bool searchElementBetter(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {

            if (matrix[i][0] <= target && target <= matrix[i][m - 1])
            {
                int low = 0, high = m - 1;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] < target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
        return false;
    }

    // 3. OPTIMAL: Staircase Search from Top-Right
    // Time Complexity: O(N + M) | Space Complexity: O(1)
    bool searchElementOptimal(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m - 1;

        // Loop runs until we fall off the bottom or left edge
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {

                col--;
            }
            else
            {

                row++;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 14;

    cout << "Brute Force : " << (obj.searchElementBrute(matrix, target) ? "Found" : "Not Found") << "\n";
    cout << "Better      : " << (obj.searchElementBetter(matrix, target) ? "Found" : "Not Found") << "\n";
    cout << "Optimal     : " << (obj.searchElementOptimal(matrix, target) ? "Found" : "Not Found") << "\n";

    return 0;
}