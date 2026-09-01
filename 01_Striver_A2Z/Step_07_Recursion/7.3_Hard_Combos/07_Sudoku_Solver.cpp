#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // O(1) space, O(9) time validation check
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check the column
            if (board[i][col] == c)
                return false;

            // Check the row
            if (board[row][i] == c)
                return false;

            // Check the 3x3 sub-box
            // Formula to find the top-left corner of the sub-box: 3 * (row / 3) and 3 * (col / 3)
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        // Traverse the entire 9x9 board to find the next empty cell
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                // If we find an empty cell, we must fill it
                if (board[i][j] == '.')
                {

                    // Try all possible digits from 1 to 9
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {

                            // Pick the digit
                            board[i][j] = c;

                            // Recurse to solve the rest of the board
                            // SHORT-CIRCUIT: If it works, stop entirely.
                            if (solve(board))
                            {
                                return true;
                            }

                            // Backtrack: Remove the digit to try the next one
                            board[i][j] = '.';
                        }
                    }
                    // If we tried 1-9 and none worked, this branch is fundamentally flawed
                    return false;
                }
            }
        }
        // If we scanned the whole board and found no '.', we are successfully done
        return true;
    }

public:
    // OPTIMAL: DFS Backtracking with inline 3x3 block checking
    // Time Complexity: O(9^(empty cells)) worst case | Space: O(81) max for Call Stack
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    obj.solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}