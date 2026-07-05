#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int calculateDays(vector<int> &weights, int capacity)
    {
        int days = 1;
        int currentLoad = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (currentLoad + weights[i] > capacity)
            {
                days += 1;
                currentLoad = weights[i];
            }
            else
            {
                currentLoad += weights[i];
            }
        }
        return days;
    }

public:
    // 1. BRUTE FORCE: Try every capacity from max(arr) to sum(arr)
    // Time Complexity: O( (sum - max + 1) * N ) | Space Complexity: O(1)
    int shipWithinDaysBrute(vector<int> &weights, int d)
    {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        for (int capacity = maxi; capacity <= sum; capacity++)
        {
            if (calculateDays(weights, capacity) <= d)
            {
                return capacity;
            }
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search on the Answer Space
    // Time Complexity: O(N * log(sum - max + 1)) | Space Complexity: O(1)
    int shipWithinDaysOptimal(vector<int> &weights, int d)
    {
        int low = INT_MIN;
        int high = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            low = max(low, weights[i]);
            high += weights[i];
        }

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int daysNeeded = calculateDays(weights, mid);

            if (daysNeeded <= d)
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
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << "Brute Force : Capacity " << obj.shipWithinDaysBrute(weights, days) << "\n";
    cout << "Optimal     : Capacity " << obj.shipWithinDaysOptimal(weights, days) << "\n";

    return 0;
}