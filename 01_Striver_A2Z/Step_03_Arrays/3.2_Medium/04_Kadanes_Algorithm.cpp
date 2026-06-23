#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1. BRUTE: Check all possible subarrays using 3 loops
    // Time: O(N^3) | Space: O(1)
    long long maxSubarraySumBrute(vector<int> &arr)
    {
        int n = arr.size();
        long long maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                long long sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += arr[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }

    // 2. BETTER: Optimize out the 3rd loop by keeping a running sum
    // Time: O(N^2) | Space: O(1)
    long long maxSubarraySumBetter(vector<int> &arr)
    {
        int n = arr.size();
        long long maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }

    // 3. OPTIMAL: Kadane's Algorithm
    // Time: O(N) | Space: O(1)
    long long maxSubarraySumOptimal(vector<int> &arr)
    {
        long long maxi = INT_MIN;
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum > maxi)
            {
                maxi = sum;
            }

            // If the sum becomes negative, throw it away.
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Brute   : " << obj.maxSubarraySumBrute(arr) << "\n";
    cout << "Better  : " << obj.maxSubarraySumBetter(arr) << "\n";
    cout << "Optimal : " << obj.maxSubarraySumOptimal(arr) << "\n";

    return 0;
}