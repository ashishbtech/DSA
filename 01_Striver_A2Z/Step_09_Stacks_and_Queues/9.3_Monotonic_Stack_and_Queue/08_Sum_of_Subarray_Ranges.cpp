#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function reused from Problem 6
    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;

        // Previous Strictly Smaller Element
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller or Equal Element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        long long totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;
            totalSum += (leftCount * rightCount * arr[i]);
        }
        return totalSum;
    }

    // Helper function for Maximums (Inverted logic of Minimums)
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pge(n, -1); // Previous Greater Element
        vector<int> nge(n, n);  // Next Greater Element
        stack<int> st;

        // Previous Strictly Greater Element
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
                pge[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Greater or Equal Element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            if (!st.empty())
                nge[i] = st.top();
            st.push(i);
        }

        long long totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            long long leftCount = i - pge[i];
            long long rightCount = nge[i] - i;
            totalSum += (leftCount * rightCount * arr[i]);
        }
        return totalSum;
    }

public:
    // BRUTE FORCE: Nested loops
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    long long subArrayRangesBrute(vector<int> &nums)
    {
        long long totalRange = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int currentMin = nums[i];
            int currentMax = nums[i];
            for (int j = i; j < n; j++)
            {
                currentMin = min(currentMin, nums[j]);
                currentMax = max(currentMax, nums[j]);
                totalRange += (currentMax - currentMin);
            }
        }
        return totalRange;
    }

    // OPTIMAL: Sum of Maximums - Sum of Minimums
    // Time Complexity: O(N) | Space Complexity: O(N)
    long long subArrayRangesOptimal(vector<int> &nums)
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3};

    cout << "Brute Force: " << obj.subArrayRangesBrute(nums) << "\n";
    cout << "Optimal: " << obj.subArrayRangesOptimal(nums) << "\n";

    return 0;
}