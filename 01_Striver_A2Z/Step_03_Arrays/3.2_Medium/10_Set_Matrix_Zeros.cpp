#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: When you find a 0, turn its row/col non-zero elements into -999999.
    // After scanning the whole board, do a 2nd pass turning all -999999s into 0s.
    // Time Complexity: O((N*M) * (N + M)) ≈ O(N^3) | Space Complexity: O(1)
    void setZeroesBrute(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Mark row 'i'
                    for (int k = 0; k < m; k++)
                    {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = -999999;
                    }
                    // Mark col 'j'
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = -999999;
                    }
                }
            }
        }

        // Second pass: solidify the markers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -999999)
                    matrix[i][j] = 0;
            }
        }
    }

    // 2. BETTER: Allocate two separate dummy arrays: row[n] and col[m]
    // Time Complexity: O(2 * N * M) | Space Complexity: O(N + M) auxiliary
    void setZeroesBetter(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Pass 1: Drop flags in our dummy arrays
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Pass 2: Look at the dummy flags to decide the cell's fate
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // 3. OPTIMAL: Collapse the dummy arrays inside the matrix's own 0th Row and 0th Col.
    // Time Complexity: O(2 * N * M) | Space Complexity: Strictly O(1)
    void setZeroesOptimal(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1; // THE BOSS VARIABLE: prevents row[0] and col[0] from overwriting each other at matrix[0][0]

        // Step 1: Traverse and mark reference anchors in the top row and left column
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark the row anchor

                    if (j == 0)
                        col0 = 0; // Special check for the very first column
                    else
                        matrix[0][j] = 0; // Mark the regular column anchor
                }
            }
        }

        // Step 2: Transform the "inner" sub-matrix (from cell 1,1 down to bottom right)
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Resolve the first row (Depends strictly on what sits at matrix[0][0])
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // Step 4: Resolve the first column (Depends strictly on our detached col0 variable)
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};

int main()
{
    Solution obj;
    // 3x4 Matrix test case
    vector<vector<int>> raw = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    vector<vector<int>> mBrute = raw;
    obj.setZeroesBrute(mBrute);

    cout << "Brute Force Output (O(1) Space):\n";
    for (auto &row : mBrute)
    {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    vector<vector<int>> mBetter = raw;
    obj.setZeroesBetter(mBetter);

    cout << "\nBetter Output (O(N+M) Space):\n";
    for (auto &row : mBetter)
    {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    // vector<vector<int>> mBetter = raw;
    // obj.setZeroesBetter(mBetter);

    // cout << "Better Output (O(N+M) Space):\n";
    // for (auto &row : mBetter)
    // {
    //     for (int val : row)
    //         cout << val << " ";
    //     cout << "\n";
    // }

    vector<vector<int>> mOptimal = raw;
    obj.setZeroesOptimal(mOptimal);

    cout << "\nOptimal Output (O(1) Space):\n";
    for (auto &row : mOptimal)
    {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}