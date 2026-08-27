#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    void solve(vector<int> &nums, int i, vector<int> &temp)
    {
        if (i >= nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);
        temp.pop_back();
        solve(nums, i + 1, temp);
    }

    // OPTIMAL: Recursion
    // Time Complexity: O(2^n) | Space Complexity: O(N) auxiliary stack space
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        solve(nums, 0, temp);
        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = obj.subsets(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}