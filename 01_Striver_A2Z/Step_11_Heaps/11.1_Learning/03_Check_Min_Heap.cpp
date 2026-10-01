#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Check every single node and its potential children bounds
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool isMinHeapBrute(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // If left child exists and is smaller than parent
            if (left < n && arr[i] > arr[left])
            {
                return false;
            }
            // If right child exists and is smaller than parent
            if (right < n && arr[i] > arr[right])
            {
                return false;
            }
        }

        return true;
    }

    // OPTIMAL: Only check non-leaf nodes (indices 0 to n/2 - 1)
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool isMinHeapOptimal(vector<int> &arr)
    {
        int n = arr.size();

        // Loop only up to the last non-leaf node
        for (int i = 0; i < (n / 2); i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Left child is guaranteed to exist for indices < n/2
            if (arr[i] > arr[left])
            {
                return false;
            }

            // Right child might not exist for the very last non-leaf node if N is even
            if (right < n && arr[i] > arr[right])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    cout << "Array 1: [1, 2, 3, 4, 5, 6]\n";
    cout << "Brute Force: " << (obj.isMinHeapBrute(arr1) ? "True" : "False") << "\n";
    cout << "Optimal: " << (obj.isMinHeapOptimal(arr1) ? "True" : "False") << "\n";

    cout << "---\n";

    vector<int> arr2 = {1, 5, 3, 4, 6};
    cout << "Array 2: [1, 5, 3, 4, 6]\n";
    cout << "Optimal: " << (obj.isMinHeapOptimal(arr2) ? "True" : "False") << "\n";

    return 0;
}