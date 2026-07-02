#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. ITERATIVE: Standard Binary Search
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int searchIterative(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            // (high - low) / 2 prevents integer overflow for massive arrays
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
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

    // 2. RECURSIVE: Standard Binary Search
    // Time Complexity: O(log N) | Space Complexity: O(log N) call stack space
    int bsRecursive(vector<int> &arr, int low, int high, int target)
    {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2; // same reason as iterative one

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return bsRecursive(arr, mid + 1, high, target);
        }
        else
        {
            return bsRecursive(arr, low, mid - 1, target);
        }
    }

    int searchRecursive(vector<int> &arr, int target)
    {
        return bsRecursive(arr, 0, arr.size() - 1, target);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << "1. Iterative : Index " << obj.searchIterative(arr, target) << "\n";
    cout << "2. Recursive : Index " << obj.searchRecursive(arr, target) << "\n";

    return 0;
}