#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, int target, vector<int> &arr, vector<int> &current, vector<vector<int>> &ans)
    {
        // Base case
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {

            if (i > ind && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            current.push_back(arr[i]);

            solve(i + 1, target - arr[i], arr, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

public:
    // OPTIMAL: For-Loop Branching with Sorted Array to Avoid Duplicates
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates, current, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = obj.combinationSum2(candidates, target);

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