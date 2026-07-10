#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int lowerBound(vector<int> &arr, int m, int target)
    {
        int low = 0, high = m - 1;
        int ans = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    // 1. BRUTE FORCE: Traverse every cell
    // Time Complexity: O(N * M) | Space Complexity: O(1)
    int rowWithMax1sBrute(vector<vector<int>> &matrix, int n, int m)
    {
        int max_ones = 0;
        int max_index = -1;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    count++;
                }
            }
            if (count > max_ones)
            {
                max_ones = count;
                max_index = i;
            }
        }
        return max_index;
    }

    // 2. OPTIMAL: Binary Search (Lower Bound) on each row
    // Time Complexity: O(N * log M) | Space Complexity: O(1)
    int rowWithMax1sOptimal(vector<vector<int>> &matrix, int n, int m)
    {
        int max_ones = 0;
        int max_index = -1;

        for (int i = 0; i < n; i++)
        {
            int first_one_idx = lowerBound(matrix[i], m, 1);

            int count_ones = m - first_one_idx;

            if (count_ones > max_ones)
            {
                max_ones = count_ones;
                max_index = i;
            }
        }
        return max_index;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Brute Force : Row " << obj.rowWithMax1sBrute(matrix, n, m) << "\n";
    cout << "Optimal     : Row " << obj.rowWithMax1sOptimal(matrix, n, m) << "\n";

    return 0;
}