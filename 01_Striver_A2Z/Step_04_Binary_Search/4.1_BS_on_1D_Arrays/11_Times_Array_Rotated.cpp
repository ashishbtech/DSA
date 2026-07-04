#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear Search to find the index of the minimum
    // Time Complexity: O(N) | Space Complexity: O(1)
    int findKRotationBrute(vector<int> &arr)
    {
        int n = arr.size();
        int minVal = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < minVal)
            {
                minVal = arr[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    // 2. OPTIMAL: Binary Search extracting the index of the minimum
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int findKRotationOptimal(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high)
        {
            // OPTIMIZATION: If the search space is already sorted,
            // the minimum is at 'low'. Update and break.
            if (arr[low] <= arr[high])
            {
                if (arr[low] < ans)
                {
                    ans = arr[low];
                    index = low;
                }
                break;
            }

            int mid = low + (high - low) / 2;

            // CHECKPOINT 1: Is the LEFT half sorted?
            if (arr[low] <= arr[mid])
            {

                if (arr[low] < ans)
                {
                    ans = arr[low];
                    index = low;
                }
                low = mid + 1;
            }
            // CHECKPOINT 2: RIGHT half must be sorted.
            else
            {

                if (arr[mid] < ans)
                {
                    ans = arr[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    // The minimum is 0, which is sitting at index 4.
    // That means the array was rotated 4 times.

    cout << "Brute Force : " << obj.findKRotationBrute(arr) << " times\n";
    cout << "Optimal     : " << obj.findKRotationOptimal(arr) << " times\n";

    return 0;
}