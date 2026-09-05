#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Bit Manipulation representation of subsets
    // Time Complexity: O(2^N * N) | Space Complexity: O(2^N * N) to store the answer
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^N subsets

        vector<vector<int>> ans;

        // Loop from 0 to (2^N - 1)
        for (int num = 0; num < totalSubsets; num++)
        {
            vector<int> currentSubset;

            // Check each of the N bits
            for (int i = 0; i < n; i++)
            {

                // If the i-th bit is set, include nums[i]
                if ((num & (1 << i)) != 0)
                {
                    currentSubset.push_back(nums[i]);
                }
            }

            ans.push_back(currentSubset);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.subsets(nums);

    cout << "Power Set of {1, 2, 3}:\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}