#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    // Helper to calculate nCr = n! / (r! * (n-r)!) for Brute Force
    int nCr(int n, int r)
    {
        long long res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    // Helper for Optimal: Generates a complete 1-indexed row in O(row) time
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); // First element of every row is always 1

        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

public:
    // 1. BRUTE FORCE: Compute every single cell independently via nCr formula
    // Time Complexity: O(N^3) | Space Complexity: O(1) auxiliary
    vector<vector<int>> generateBrute(int numRows)
    {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++)
        {
            vector<int> tempRow;
            for (int col = 1; col <= row; col++)
            {
                tempRow.push_back(nCr(row - 1, col - 1));
            }
            ans.push_back(tempRow);
        }
        return ans;
    }

    // 2. OPTIMAL: Generate each row sequentially using running multiplier
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary space
    vector<vector<int>> generateOptimal(int numRows)
    {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++)
        {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 5;

    vector<vector<int>> brute = obj.generateBrute(n);
    cout << "1. Brute Force Output (O(N^3)):\n";
    for (auto r : brute)
    {
        for (int x : r)
            cout << x << " ";
        cout << "\n";
    }

    vector<vector<int>> opt = obj.generateOptimal(n);
    cout << "\n2. Optimal Output (O(N^2)):\n";
    for (auto r : opt)
    {
        for (int x : r)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}