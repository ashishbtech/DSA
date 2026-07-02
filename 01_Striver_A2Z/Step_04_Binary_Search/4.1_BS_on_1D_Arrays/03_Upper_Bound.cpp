#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear Search
    // Time Complexity: O(N) | Space Complexity: O(1)
    int upperBoundBrute(vector<int> &arr, int target)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > target)
            {
                return i;
            }
        }
        return n;
    }

    // 2. OPTIMAL: Binary Search
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int upperBoundOptimal(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Condition for Upper Bound: arr[mid] > target
            if (arr[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    // 3. STL CHEAT CODE: For Competitive Programming
    // Time Complexity: O(log N)
    int upperBoundSTL(vector<int> &arr, int target)
    {
        return upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int target = 10;

    cout << "1. Brute Force : Index " << obj.upperBoundBrute(arr, target) << "\n";
    cout << "2. Optimal     : Index " << obj.upperBoundOptimal(arr, target) << "\n";
    cout << "3. STL 1-Liner : Index " << obj.upperBoundSTL(arr, target) << "\n";

    return 0;
}