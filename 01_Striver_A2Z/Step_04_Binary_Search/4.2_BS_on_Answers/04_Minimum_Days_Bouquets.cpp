#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool possible(vector<int> &arr, int day, int m, int k)
    {
        int n = arr.size();
        int count = 0;
        int noOfB = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                count++;
            }
            else
            {
                noOfB += (count / k);
                count = 0;
            }
        }
        noOfB += (count / k);

        return noOfB >= m;
    }

public:
    // 1. BRUTE FORCE: Try every day from min(arr) to max(arr)
    // Time Complexity: O((max - min + 1) * N) | Space Complexity: O(1)
    int minDaysBrute(vector<int> &arr, int m, int k)
    {
        long long val = 1ll * m * k;
        int n = arr.size();
        if (val > n)
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        for (int i = mini; i <= maxi; i++)
        {
            if (possible(arr, i, m, k))
            {
                return i;
            }
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search on the Answer Space
    // Time Complexity: O(N * log(max - min + 1)) | Space Complexity: O(1)
    int minDaysOptimal(vector<int> &arr, int m, int k)
    {
        long long val = 1ll * m * k;
        int n = arr.size();
        if (val > n)
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        int low = mini, high = maxi;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k))
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
    vector<int> arr = {7, 7, 7, 7, 12, 7, 7};
    int m = 2;
    int k = 3;

    cout << "Brute Force : " << obj.minDaysBrute(arr, m, k) << " days\n";
    cout << "Optimal     : " << obj.minDaysOptimal(arr, m, k) << " days\n";

    return 0;
}