#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Nested loops
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int sumSubarrayMinsBrute(vector<int> &arr)
    {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long totalSum = 0;

        for (int i = 0; i < n; i++)
        {
            int currentMin = arr[i];
            for (int j = i; j < n; j++)
            {
                currentMin = min(currentMin, arr[j]);
                totalSum = (totalSum + currentMin) % mod;
            }
        }
        return totalSum;
    }

    // OPTIMAL: Monotonic Stack (Contribution Technique)
    // Time Complexity: O(N) | Space Complexity: O(N)
    int sumSubarrayMinsOptimal(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1); // Previous Smaller Element Index
        vector<int> nse(n, n);  // Next Smaller Element Index
        stack<int> st;

        // 1. Find Previous Smaller Element (Strictly Smaller to avoid duplicate subarray counting)
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                pse[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack to reuse it
        while (!st.empty())
            st.pop();

        // 2. Find Next Smaller or Equal Element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nse[i] = st.top();
            }
            st.push(i);
        }

        // 3. Calculate Contribution
        long long totalSum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            // Number of elements to the left (including arr[i])
            long long leftCount = i - pse[i];
            // Number of elements to the right (including arr[i])
            long long rightCount = nse[i] - i;

            // Total subarrays where arr[i] is the minimum
            long long totalSubarrays = (leftCount * rightCount) % mod;

            // Contribution of arr[i] to the final sum
            long long contribution = (totalSubarrays * arr[i]) % mod;

            totalSum = (totalSum + contribution) % mod;
        }

        return totalSum;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 1, 2, 4};

    cout << "Brute Force: " << obj.sumSubarrayMinsBrute(arr) << "\n";
    cout << "Optimal: " << obj.sumSubarrayMinsOptimal(arr) << "\n";
    // Expected output for both: 17
    // Subarrays: [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
    // Minimums:   3 +  1 +  2 +  4 +   1  +   1  +   2  +    1    +    1    +     1   = 17

    return 0;
}