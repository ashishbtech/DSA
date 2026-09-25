#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Re-sum all valid left/right combinations
    // Time Complexity: O(K^2) | Space Complexity: O(1)
    int maxScoreBrute(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int maxSum = 0;

        // i represents how many cards we take from the left
        for (int i = 0; i <= k; i++)
        {
            int currentSum = 0;

            // Sum 'i' elements from the left
            for (int j = 0; j < i; j++)
            {
                currentSum += cardPoints[j];
            }
            // Sum 'k - i' elements from the right
            for (int j = n - (k - i); j < n; j++)
            {
                currentSum += cardPoints[j];
            }

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }

    // OPTIMAL: Sliding window transferring elements from left to right
    // Time Complexity: O(K) | Space Complexity: O(1)
    int maxScoreOptimal(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;

        // Step 1: Take all 'k' cards from the left
        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
        }

        maxSum = lsum;

        // Step 2: Trade one card from the left for one from the right
        int rightIndex = n - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];          // Remove the rightmost card from the left group
            rsum += cardPoints[rightIndex]; // Add the rightmost available card from the array
            rightIndex--;

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};

int main()
{
    Solution obj;

    vector<int> cards1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << "Cards: [1, 2, 3, 4, 5, 6, 1] | k = 3\n";
    cout << "Brute Force: " << obj.maxScoreBrute(cards1, k1) << "\n";
    cout << "Optimal: " << obj.maxScoreOptimal(cards1, k1) << "\n";

    cout << "---\n";

    vector<int> cards2 = {2, 2, 2};
    int k2 = 2;
    cout << "Cards: [2, 2, 2] | k = 2\n";
    cout << "Optimal: " << obj.maxScoreOptimal(cards2, k2) << "\n";

    cout << "---\n";

    vector<int> cards3 = {9, 7, 7, 9, 7, 7, 9};
    int k3 = 7;
    cout << "Cards: [9, 7, 7, 9, 7, 7, 9] | k = 7\n";
    cout << "Optimal: " << obj.maxScoreOptimal(cards3, k3) << "\n";

    return 0;
}