#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool searchWord(int row, int col, int index, vector<vector<char>> &board, string &word)
    {
        // Base Case 1: All characters matched
        if (index == word.length())
        {
            return true;
        }

        // Base Case 2: Out of bounds or character mismatch
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
        {
            return false;
        }

        // Temporarily mark the cell as visited to prevent looping back
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 adjacent directions
        bool found = searchWord(row - 1, col, index + 1, board, word) || // Up
                     searchWord(row + 1, col, index + 1, board, word) || // Down
                     searchWord(row, col - 1, index + 1, board, word) || // Left
                     searchWord(row, col + 1, index + 1, board, word);   // Right

        // BACKTRACK: Restore the cell's original character
        board[row][col] = temp;

        return found;
    }

public:
    // OPTIMAL: Backtracking with in-place visited marking
    // Time Complexity: O(M * N * 4^L) where L is length of word
    // Space Complexity: O(L) for Call Stack
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Check every single cell to find a valid starting point
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {

                // If the first letter matches, start the deep search
                if (board[r][c] == word[0])
                {
                    if (searchWord(r, c, 0, board, word))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    if (obj.exist(board, word))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}