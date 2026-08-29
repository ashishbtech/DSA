#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int start, int target, int k, vector<int> &current, vector<vector<int>> &ans)
    {
        // Base case
        if (current.size() == k)
        {
            // Check if they sum perfectly to our target
            if (target == 0)
            {
                ans.push_back(current);
            }
            return;
        }

        // Loop through the valid digits from 'start' to 9
        for (int i = start; i <= 9; i++)
        {

            if (i > target)
                break;

            // Pick the number
            current.push_back(i);

            // Recurse: Move to the next number (i + 1) and reduce the target
            solve(i + 1, target - i, k, current, ans);

            // Backtrack: Remove the number to try the next one in the loop
            current.pop_back();
        }
    }

public:
    // OPTIMAL: For-Loop backtracking bounded by 1-9 and size k
    // Time Complexity: O(C(9, k)) which is extremely small | Space: O(k) for Call Stack
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> current;

        // Start the recursion with the number 1
        solve(1, n, k, current, ans);

        return ans;
    }
};

int main()
{
    Solution obj;
    int k = 3;
    int n = 7;

    vector<vector<int>> ans = obj.combinationSum3(k, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}