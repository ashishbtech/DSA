#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int k)
    {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            totalHours += ceil((double)piles[i] / (double)k);
        }
        return totalHours;
    }

public:
    // 1. BRUTE FORCE: Try every speed from 1 to max(piles)
    // Time Complexity: O(max(piles) * N) | Space Complexity: O(1)
    int minEatingSpeedBrute(vector<int> &piles, int h)
    {
        int maxi = findMax(piles);

        for (int i = 1; i <= maxi; i++)
        {
            long long reqTime = calculateTotalHours(piles, i);
            if (reqTime <= h)
            {
                return i;
            }
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search on the Answer Space
    // Time Complexity: O(N * log(max(piles))) | Space Complexity: O(1)
    int minEatingSpeedOptimal(vector<int> &piles, int h)
    {
        int low = 1, high = findMax(piles);
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long reqTime = calculateTotalHours(piles, mid);

            if (reqTime <= h)
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
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Brute Force : " << obj.minEatingSpeedBrute(piles, h) << " bananas/hr\n";
    cout << "Optimal     : " << obj.minEatingSpeedOptimal(piles, h) << " bananas/hr\n";

    return 0;
}