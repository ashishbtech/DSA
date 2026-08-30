#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {

        // Check row
        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
            {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string> &board, int row, int n,
                 vector<vector<string>> &ans)
    {

        // All queens placed
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column
        for (int j = 0; j < n; j++)
        {

            if (isSafe(board, row, j, n))
            {

                board[row][j] = 'Q';

                nQueens(board, row + 1, n, ans);

                // Backtracking
                board[row][j] = '.';
            }
        }
    }

public:
    // OPTIMAL: Backtracking
    // Time Complexity:  O(N * N!)| Space Complexity: O(N^2)
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);

        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 4;

    vector<vector<string>> ans = obj.solveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "\n";
        }
        cout << "\n";
    }

    return 0;
}