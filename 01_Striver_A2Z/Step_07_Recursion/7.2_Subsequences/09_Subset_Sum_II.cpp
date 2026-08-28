#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans)
    {

        ans.push_back(current);

        for (int i = ind; i < nums.size(); i++)
        {

            if (i > ind && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);

            solve(i + 1, nums, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

public:
    // OPTIMAL: For-Loop Branching to strictly avoid generating duplicate subsets
    // Time Complexity: O(2^N * N) | Space Complexity: O(2^N * K) for storing answers
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> current;

        sort(nums.begin(), nums.end());

        solve(0, nums, current, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

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