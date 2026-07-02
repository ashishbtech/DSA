#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Binary Search (Identical to Lower Bound)
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int searchInsert(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
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
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 3, 5, 6};

    cout << "Target 5 (Exists)  : Insert at index " << obj.searchInsert(arr, 5) << "\n";
    cout << "Target 2 (Missing) : Insert at index " << obj.searchInsert(arr, 2) << "\n";
    cout << "Target 7 (Missing) : Insert at index " << obj.searchInsert(arr, 7) << "\n";

    return 0;
}