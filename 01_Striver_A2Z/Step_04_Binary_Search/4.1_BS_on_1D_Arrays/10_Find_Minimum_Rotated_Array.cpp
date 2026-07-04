#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear Search
    // Time Complexity: O(N) | Space Complexity: O(1)
    int findMinBrute(vector<int> &arr)
    {
        int mini = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            mini = min(mini, arr[i]);
        }
        return mini;
    }

    // 2. OPTIMAL: Binary Search extracting the minimum from the sorted half
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int findMinOptimal(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high)
        {
            /*---- more optimization pure optional ----*/
            
            // if (arr[low] <= arr[high])
            // {
            //     ans = min(ans, arr[low]);
            //     break;
            // }

            int mid = low + (high - low) / 2;

            
            if (arr[low] <= arr[mid])
            {
                
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            else
            {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << "Brute Force : " << obj.findMinBrute(arr) << "\n";
    cout << "Optimal     : " << obj.findMinOptimal(arr) << "\n";

    return 0;
}