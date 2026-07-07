#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool canWePlace(vector<int> &stalls, int dist, int cows)
    {
        int n = stalls.size();
        int cowsPlaced = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - lastPos >= dist)
            {
                cowsPlaced++;
                lastPos = stalls[i];
            }

            if (cowsPlaced >= cows)
            {
                return true;
            }
        }
        return false;
    }

public:
    // 1. BRUTE FORCE: Linear Search from 1 to max possible distance
    // Time Complexity: O(N log N) + O(N * (max-min)) | Space Complexity: O(1)
    int aggressiveCowsBrute(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());

        int limit = stalls[n - 1] - stalls[0];

        for (int i = 1; i <= limit; i++)
        {
            if (canWePlace(stalls, i, k) == false)
            {
                return i - 1;
            }
        }
        return limit;
    }

    // 2. OPTIMAL: Binary Search on Answer Space
    // Time Complexity: O(N log N) + O(N * log(max-min)) | Space Complexity: O(1)
    int aggressiveCowsOptimal(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int ans = 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canWePlace(stalls, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;

    cout << "Brute Force : " << obj.aggressiveCowsBrute(stalls, k) << "\n";
    cout << "Optimal     : " << obj.aggressiveCowsOptimal(stalls, k) << "\n";

    return 0;
}