#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int calculateSum(vector<int> &arr, int divisor)
    {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)(arr[i]) / (double)(divisor));
        }
        return sum;
    }

public:
    // 1. BRUTE FORCE: Try every divisor from 1 to max(arr)
    // Time Complexity: O(max(arr) * N) | Space Complexity: O(1)
    int smallestDivisorBrute(vector<int> &arr, int threshold)
    {
        int n = arr.size();
        if (n > threshold)
            return -1;

        int maxi = *max_element(arr.begin(), arr.end());

        for (int d = 1; d <= maxi; d++)
        {
            int sum = calculateSum(arr, d);
            if (sum <= threshold)
            {
                return d;
            }
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search on Answer Space
    // Time Complexity: O(N * log(max(arr))) | Space Complexity: O(1)
    int smallestDivisorOptimal(vector<int> &arr, int threshold)
    {
        int n = arr.size();
        if (n > threshold)
            return -1;

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int currentSum = calculateSum(arr, mid);

            if (currentSum <= threshold)
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
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Brute Force : Divisor " << obj.smallestDivisorBrute(arr, threshold) << "\n";
    cout << "Optimal     : Divisor " << obj.smallestDivisorOptimal(arr, threshold) << "\n";

    return 0;
}