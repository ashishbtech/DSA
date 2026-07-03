#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear Search
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool searchBrute(vector<int> &arr, int target)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
                return true;
        }
        return false;
    }

    // 2. OPTIMAL: Modified Binary Search with Shrink Edge Case
    // Time Complexity: Avg O(log N), Worst O(N) | Space Complexity: O(1)
    bool searchOptimal(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return true;

            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }

            if (arr[low] <= arr[mid])
            {

                if (arr[low] <= target && target <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            else
            {

                if (arr[mid] <= target && target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
    int target = 2;

    cout << "Brute Force : " << (obj.searchBrute(arr, target) ? "Found" : "Not Found") << "\n";
    cout << "Optimal     : " << (obj.searchOptimal(arr, target) ? "Found" : "Not Found") << "\n";

    return 0;
}