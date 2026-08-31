#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int row, int col, vector<vector<int>> &m, int n, string currentPath, vector<string> &ans)
    {
        // Base case: Rat reached the bottom-right destination
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(currentPath);
            return;
        }

        // Mark the current cell as visited by temporarily turning it into a wall
        m[row][col] = 0;

        // Explore all 4 directions in LEXICOGRAPHICAL order (D, L, R, U)

        // 1. DOWN
        if (row + 1 < n && m[row + 1][col] == 1)
        {
            solve(row + 1, col, m, n, currentPath + 'D', ans);
        }
        // 2. LEFT
        if (col - 1 >= 0 && m[row][col - 1] == 1)
        {
            solve(row, col - 1, m, n, currentPath + 'L', ans);
        }
        // 3. RIGHT
        if (col + 1 < n && m[row][col + 1] == 1)
        {
            solve(row, col + 1, m, n, currentPath + 'R', ans);
        }
        // 4. UP
        if (row - 1 >= 0 && m[row - 1][col] == 1)
        {
            solve(row - 1, col, m, n, currentPath + 'U', ans);
        }

        // Backtrack: Unmark the cell so other paths can use it
        m[row][col] = 1;
    }

public:
    // OPTIMAL: DFS Backtracking with D-L-R-U ordering
    // Time Complexity: O(4^(M*N)) worst case | Space: O(M*N) Call Stack
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;

        // Edge case: If the starting cell or ending cell is blocked
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
            return ans;

        solve(0, 0, m, n, "", ans);

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int n = m.size();

    vector<string> ans = obj.findPath(m, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}