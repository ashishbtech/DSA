#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countSubsets(int i, int currentSum, vector<int> &arr, int target)
    {
        // Base Case: We have made a choice for every single element
        if (i == arr.size())
        {
            if (currentSum == target)
            {
                return 1; // Found a valid subset
            }
            else
            {
                return 0; // Invalid subset
            }
        }

        // Choice 1: Pick the current element
        int pick = countSubsets(i + 1, currentSum + arr[i], arr, target);

        // Choice 2: Don't pick the current element
        int dontPick = countSubsets(i + 1, currentSum, arr, target);

        // Bubble up the total successful paths from both choices
        return pick + dontPick;
    }

public:
    //    TLE will hit, optimization can be done with dyanmmic programming
    // Time Complexity: O(2^n) | Space Complexity: O(N)
    int perfectSum(vector<int> &arr, int target)
    {
        return countSubsets(0, 0, arr, target);
    }
};

int main()
{
    Solution obj;
    // vector<int> arr = {5, 2, 3, 10, 6, 8};
    vector<int> arr = {2, 3, 0};
    // int target = 10;
    int target = 5;
    // int n = arr.size();

    cout << obj.perfectSum(arr, target) << endl;

    return 0;
}