#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkSubset(int i, int currentSum, vector<int> &arr, int target)
    {
        // Base Case 1: Target reached! Stop exploring this path.
        if (currentSum == target)
        {
            return true;
        }

        // Base Case 2: Array ended OR sum exceeded target (pruning)
        if (i == arr.size() || currentSum > target)
        {
            return false;
        }

        // Choice 1: Pick the current element
        // If picking it eventually leads to the target, return true immediately.
        if (checkSubset(i + 1, currentSum + arr[i], arr, target) == true)
        {
            return true;
        }

        // Choice 2: Don't pick the current element
        // If picking didn't work, check if skipping works.
        if (checkSubset(i + 1, currentSum, arr, target) == true)
        {
            return true;
        }

        return false;
    }

public:
    // OPTIMAL Pure Pick/Don't Pick Recursion with Short-Circuit
    // Time Complexity: O(2^N) | Space Complexity: O(N) for Call Stack
    bool checkSubsequenceSum(vector<int> &arr, int k)
    {
        return checkSubset(0, 0, arr, k);
    }
};

int main()
{
    Solution obj;
    // vector<int> arr = {4, 3, 2, 1};
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    // int k = 5;
    int k = 8;
    // int n = arr.size();

    if (obj.checkSubsequenceSum(arr, k))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}