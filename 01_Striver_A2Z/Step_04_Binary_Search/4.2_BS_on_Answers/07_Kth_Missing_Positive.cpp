#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Shift K as we find numbers smaller than it
    // Time Complexity: O(N) | Space Complexity: O(1)
    int findKthPositiveBrute(vector<int> &arr, int k)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }

    // 2. OPTIMAL: Binary Search on Indices using the Missing Math Formula
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int findKthPositiveOptimal(vector<int> &arr, int k)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int missingBeforeMid = arr[mid] - (mid + 1);

            if (missingBeforeMid < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low + k;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Brute Force : " << obj.findKthPositiveBrute(arr, k) << "\n";
    cout << "Optimal     : " << obj.findKthPositiveOptimal(arr, k) << "\n";

    return 0;
}