#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findMaxIndex(vector<vector<int>> &matrix, int n, int col)
    {
        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][col] > maxValue)
            {
                maxValue = matrix[i][col];
                index = i;
            }
        }
        return index;
    }

public:
    // 1. BRUTE FORCE: Traverse every cell and check all 4 neighbors
    // Time Complexity: O(N * M * 4) ~ O(N * M) | Space Complexity: O(1)
    vector<int> findPeakGridBrute(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Check all 4 directions with out-of-bounds protection (-1 perimeter)
                int top = (i > 0) ? mat[i - 1][j] : -1;
                int bottom = (i < n - 1) ? mat[i + 1][j] : -1;
                int left = (j > 0) ? mat[i][j - 1] : -1;
                int right = (j < m - 1) ? mat[i][j + 1] : -1;

                if (mat[i][j] > top && mat[i][j] > bottom &&
                    mat[i][j] > left && mat[i][j] > right)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    // 2. OPTIMAL: Binary Search on Columns + Row Max Greedy Choice
    // Time Complexity: O(N * log M) | Space Complexity: O(1)
    vector<int> findPeakGridOptimal(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Step 1: Find the max element in the middle column (beats top & bottom automatically)
            int maxRowIndex = findMaxIndex(mat, n, mid);

            // Step 2: Grab left and right neighbors (with boundary fallbacks)
            int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;

            // Step 3: Check if it's a 2D peak
            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
            {
                return {maxRowIndex, mid};
            }
            // Step 4: Walk towards the rising slope
            else if (mat[maxRowIndex][mid] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}};

    vector<int> bruteAns = obj.findPeakGridBrute(mat);
    cout << "Brute Force : Peak found at [" << bruteAns[0] << ", " << bruteAns[1] << "]\n";

    vector<int> optimalAns = obj.findPeakGridOptimal(mat);
    cout << "Optimal     : Peak found at [" << optimalAns[0] << ", " << optimalAns[1] << "]\n";

    return 0;
}