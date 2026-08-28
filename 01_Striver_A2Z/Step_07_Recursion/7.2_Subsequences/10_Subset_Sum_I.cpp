#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, int currentSum, vector<int> &arr, vector<int> &ans)
    {

        if (ind == arr.size())
        {
            ans.push_back(currentSum);
            return;
        }

        solve(ind + 1, currentSum + arr[ind], arr, ans);

        solve(ind + 1, currentSum, arr, ans);
    }

public:
    // OPTIMAL: Pure Pick/Don't Pick tracking only the sum
    // Time Complexity: O(2^N) | Space Complexity: O(2^N) to store sums
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        solve(0, 0, arr, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 3};
    int n = arr.size();

    vector<int> ans = obj.subsetSums(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}