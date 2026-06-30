#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: 3 nested loops (Generate all subarrays and sum them up)
    // Time Complexity: O(N^3) | Space Complexity: O(1)
    int subarraysXorBrute(vector<int> &arr, int k)
    {
        int n = arr.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int xorSum = 0;
                for (int l = i; l <= j; l++)
                {
                    xorSum = xorSum ^ arr[l];
                }
                if (xorSum == k)
                    cnt++;
            }
        }
        return cnt;
    }

    // 2. BETTER: Optimize out the 3rd loop by maintaining a running XOR
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int subarraysXorBetter(vector<int> &arr, int k)
    {
        int n = arr.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int xorSum = 0;
            for (int j = i; j < n; j++)
            {
                xorSum = xorSum ^ arr[j];
                if (xorSum == k)
                    cnt++;
            }
        }
        return cnt;
    }

    // 3. OPTIMAL: Prefix XOR + Hash Map
    // Formula: If (runningXOR ^ k) exists in map, add its historical frequency to count.
    // Time Complexity: O(N) | Space Complexity: O(N)
    int subarraysXorOptimal(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int xr = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            xr = xr ^ arr[i];

            // By bitwise algebra: targetPrefix = currentXOR ^ k
            int targetPrefix = xr ^ k;

            if (mpp.find(targetPrefix) != mpp.end())
            {
                cnt += mpp[targetPrefix];
            }

            mpp[xr]++;
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "1. Brute Force : " << obj.subarraysXorBrute(arr, k) << " subarrays (O(N^3))\n";
    cout << "2. Better      : " << obj.subarraysXorBetter(arr, k) << " subarrays (O(N^2))\n";
    cout << "3. Optimal     : " << obj.subarraysXorOptimal(arr, k) << " subarrays (O(N))\n";

    return 0;
}