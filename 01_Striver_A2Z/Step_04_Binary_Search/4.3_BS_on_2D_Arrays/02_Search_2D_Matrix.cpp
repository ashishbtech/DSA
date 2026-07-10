#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Traverse the entire matrix
    // Time Complexity: O(M * N) | Space Complexity: O(1)
    bool searchMatrixBrute(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }

    // 2. BETTER: Binary Search on each row individually
    // Time Complexity: O(M * log N) | Space Complexity: O(1)
    bool searchMatrixBetter(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {

            if (matrix[i][0] <= target && target <= matrix[i][n - 1])
            {
                int low = 0, high = n - 1;
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
                return false;
            }
        }
        return false;
    }

    // 3. OPTIMAL: Flatten mathematically and Binary Search once
    // Time Complexity: O(log(M * N)) | Space Complexity: O(1)
    bool searchMatrixOptimal(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        int low = 0;
        int high = (m * n) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;

    cout << "Brute Force : " << (obj.searchMatrixBrute(matrix, target) ? "Found" : "Not Found") << "\n";
    cout << "Better      : " << (obj.searchMatrixBetter(matrix, target) ? "Found" : "Not Found") << "\n";
    cout << "Optimal     : " << (obj.searchMatrixOptimal(matrix, target) ? "Found" : "Not Found") << "\n";

    return 0;
}