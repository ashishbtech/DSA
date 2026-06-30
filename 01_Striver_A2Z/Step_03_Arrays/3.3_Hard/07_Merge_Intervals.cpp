#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Sort, then use a nested loop to stretch the interval bounds
    // Time Complexity: O(N log N) + O(2N) | Space Complexity: O(N) for answer
    vector<vector<int>> mergeBrute(vector<vector<int>> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];

            if (!ans.empty() && end <= ans.back()[1])
            {
                continue;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (arr[j][0] <= end)
                {
                    end = max(end, arr[j][1]);
                }
                else
                {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }

    // 2. OPTIMAL: Sort, then do a single pass updating the tail of the answer array
    // Time Complexity: O(N log N) + O(N) | Space Complexity: O(N) for answer
    vector<vector<int>> mergeOptimal(vector<vector<int>> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || arr[i][0] > ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> brute = obj.mergeBrute(arr);
    cout << "Brute   : ";
    for (auto &it : brute)
        cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << "\n";

    vector<vector<int>> opt = obj.mergeOptimal(arr);
    cout << "Optimal : ";
    for (auto &it : opt)
        cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << "\n";

    return 0;
}