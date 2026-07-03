#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear Search
    // Time Complexity: O(N) | Space Complexity: O(1)
    int searchBrute(vector<int> &arr, int target)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
                return i;
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search by identifying the sorted half
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int searchOptimal(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            // CHECKPOINT 1: Is the LEFT half sorted?
            if (arr[low] <= arr[mid])
            {
                // Does the target exist inside this perfectly sorted left half?
                if (arr[low] <= target && target <= arr[mid])
                {
                    high = mid - 1; // Target is here, discard right half
                }
                else
                {
                    low = mid + 1; // Target isn't here, discard left half
                }
            }
            // CHECKPOINT 2: If left isn't sorted, the RIGHT half must be sorted.
            else
            {
                // Does the target exist inside this perfectly sorted right half?
                if (arr[mid] <= target && target <= arr[high])
                {
                    low = mid + 1; // Target is here, discard left half
                }
                else
                {
                    high = mid - 1; // Target isn't here, discard right half
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Brute Force : Index " << obj.searchBrute(arr, target) << "\n";
    cout << "Optimal     : Index " << obj.searchOptimal(arr, target) << "\n";

    return 0;
}