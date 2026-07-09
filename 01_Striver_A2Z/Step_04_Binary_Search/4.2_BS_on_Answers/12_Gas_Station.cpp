#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function for Optimal BS
    int countRequiredStations(vector<int> &arr, double maxDist)
    {
        int count = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            double gap = arr[i] - arr[i - 1];
            int stationsInBetween = gap / maxDist;
            if (gap == stationsInBetween * maxDist)
            {
                stationsInBetween--;
            }
            count += stationsInBetween;
        }
        return count;
    }

public:
    // 1. BRUTE FORCE: Place stations one by one into the largest current gap
    // Time Complexity: O(K * N) | Space Complexity: O(N)
    double findSmallestMaxDistBrute(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // Tracks stations added to each gap

        // Place k stations one by one
        for (int gasStations = 1; gasStations <= k; gasStations++)
        {
            double maxSection = -1;
            int maxIndex = -1;

            // Scan all gaps to find the one that is currently the largest
            for (int i = 0; i < n - 1; i++)
            {
                double diff = arr[i + 1] - arr[i];
                double sectionLength = diff / (double)(howMany[i] + 1);

                if (sectionLength > maxSection)
                {
                    maxSection = sectionLength;
                    maxIndex = i;
                }
            }
            // Add one station to the largest gap
            howMany[maxIndex]++;
        }

        // Find the maximum gap after all k stations are placed
        double maxAns = -1;
        for (int i = 0; i < n - 1; i++)
        {
            double diff = arr[i + 1] - arr[i];
            double sectionLength = diff / (double)(howMany[i] + 1);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }

    // 2. OPTIMAL: Binary Search on Floating Point Answer Space
    // Time Complexity: O(N * log(Max_Gap / 10^-6)) | Space Complexity: O(1)
    double findSmallestMaxDistOptimal(vector<int> &arr, int k)
    {
        int n = arr.size();
        double low = 0;
        double high = 0;

        for (int i = 1; i < n; i++)
        {
            high = max(high, (double)(arr[i] - arr[i - 1]));
        }

        double diff = 1e-6;

        while (high - low > diff)
        {
            double mid = low + (high - low) / 2.0;
            int stationsNeeded = countRequiredStations(arr, mid);

            if (stationsNeeded <= k)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        return high;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 5, 10};
    int k = 2;

    cout << fixed << setprecision(6);
    cout << "Brute Force : " << obj.findSmallestMaxDistBrute(arr, k) << "\n";
    cout << "Optimal     : " << obj.findSmallestMaxDistOptimal(arr, k) << "\n";

    return 0;
}