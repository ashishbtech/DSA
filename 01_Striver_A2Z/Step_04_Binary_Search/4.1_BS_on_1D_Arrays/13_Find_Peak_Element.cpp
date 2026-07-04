#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear scan checking neighbors
    // Time Complexity: O(N) | Space Complexity: O(1)
    int findPeakElementBrute(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                return i;
            }
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search using slope detection
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int findPeakElementOptimal(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }

            if (arr[mid] > arr[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};

    cout << "Brute Force : Index " << obj.findPeakElementBrute(arr) << "\n";
    cout << "Optimal     : Index " << obj.findPeakElementOptimal(arr) << "\n";

    return 0;
}