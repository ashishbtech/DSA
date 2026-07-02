#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper to find Floor: Largest number <= x
    int getFloor(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x)
            {
                ans = arr[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Helper to find Ceil: Smallest number >= x (Exactly Lower Bound)
    int getCeil(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x)
            {
                ans = arr[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    // OPTIMAL: 2 Independent Binary Searches
    // Time Complexity: O(log N) + O(log N) -> O(log N) | Space Complexity: O(1)
    pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
    {
        int floorVal = getFloor(arr, n, x);
        int ceilVal = getCeil(arr, n, x);
        return {floorVal, ceilVal};
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int n = arr.size();

    int target = 5;

    pair<int, int> ans = obj.getFloorAndCeil(arr, n, target);
    cout << "Floor : " << ans.first << "\n";
    cout << "Ceil  : " << ans.second << "\n";

    return 0;
}