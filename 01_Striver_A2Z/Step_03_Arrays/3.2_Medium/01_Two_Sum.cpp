#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Check all possible pairs using two nested loops
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    vector<int> twoSumBrute(vector<int> &arr, int target)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    // 2. BETTER (Optimal for returning INDICES): Hash Map lookup
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<int> twoSumBetter(vector<int> &arr, int target)
    {
        unordered_map<int, int> mpp;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int needed = target - arr[i];
            // If the needed complement exists in our map, we found our pair
            if (mpp.find(needed) != mpp.end())
            {
                return {mpp[needed], i};
            }
            // Otherwise, store the current element and its index
            mpp[arr[i]] = i;
        }
        return {-1, -1};
    }

    // 3. OPTIMAL (Strictly for returning YES/NO): Two-Pointer after Sorting
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    bool twoSumOptimal(vector<int> arr, int target)
    { // Passed by value to sort a copy
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;

        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    cout << "--- Problem 1: Two Sum (Target: " << target << ") ---\n\n";

    vector<int> ansBrute = obj.twoSumBrute(arr, target);
    cout << "1. Brute Force Output : [" << ansBrute[0] << ", " << ansBrute[1] << "]  (O(N^2))\n";

    vector<int> ansBetter = obj.twoSumBetter(arr, target);
    cout << "2. Better (Map) Output: [" << ansBetter[0] << ", " << ansBetter[1] << "]  (O(N) Time, O(N) Space)\n";

    bool ansOptimal = obj.twoSumOptimal(arr, target);
    cout << "3. Optimal (2-Ptr)    : " << (ansOptimal ? "True (Pair Exists)" : "False") << " (O(N log N) Time, O(1) Space)\n";

    return 0;
}