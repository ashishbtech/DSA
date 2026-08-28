#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, int target, vector<int> &candidates, vector<int> &current, vector<vector<int>> &ans)
    {
        // Base case 1: hit the exact target sum!
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }

        // Base case 2: We ran out of elements to check
        if (ind == candidates.size())
        {
            return;
        }

        // Choice 1: Pick the current element (only if it doesn't exceed the target)
        if (candidates[ind] <= target)
        {
            current.push_back(candidates[ind]);

            // STAY at 'ind' because we are allowed to pick the same element multiple times
            solve(ind, target - candidates[ind], candidates, current, ans);

            // Backtrack: Remove the element we just added to try the next branches
            current.pop_back();
        }

        // Choice 2: Don't pick the current element, move to the next index
        solve(ind + 1, target, candidates, current, ans);
    }

public:
    // OPTIMAL: Pure Pick/Don't Pick with Infinite Supply Pattern
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, target, candidates, current, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(candidates, target);

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