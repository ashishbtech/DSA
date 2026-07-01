#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Generate all subarrays and track the maximum product
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int maxProductBrute(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int prod = 1;
            for (int j = i; j < n; j++)
            {
                prod *= arr[j];
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }

    // 2. OPTIMAL: Prefix and Suffix tracking
    // Time Complexity: O(N) | Space Complexity: O(1)
    int maxProductOptimal(vector<int> &arr)
    {
        int n = arr.size();

        double pre = 1;
        double suff = 1;
        double ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;

            pre = pre * arr[i];
            suff = suff * arr[n - 1 - i];

            ans = max({ans, pre, suff});
        }

        return (int)ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 3, -2, 4};

    cout << "1. Brute Force : " << obj.maxProductBrute(arr) << "\n";
    cout << "2. Optimal     : " << obj.maxProductOptimal(arr) << "\n";

    return 0;
}