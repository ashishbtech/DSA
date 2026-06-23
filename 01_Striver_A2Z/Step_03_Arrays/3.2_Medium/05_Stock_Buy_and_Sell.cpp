#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1. BRUTE: Check every buying day against every possible future selling day
    // Time: O(N^2) | Space: O(1)
    int maxProfitBrute(vector<int> &prices)
    {
        int maxPro = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] > prices[i])
                {
                    maxPro = max(maxPro, prices[j] - prices[i]);
                }
            }
        }
        return maxPro;
    }

    // 2. BETTER: Pre-compute the maximum price available from day 'i' to the end
    // Time: O(N) | Space: O(N) auxiliary space
    int maxProfitBetter(vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<int> maxFuture(n, 0);
        maxFuture[n - 1] = prices[n - 1];

        // Build an array looking backwards: the highest price sitting to the right of day 'i'
        for (int i = n - 2; i >= 0; i--)
        {
            maxFuture[i] = max(maxFuture[i + 1], prices[i]);
        }

        int maxPro = 0;
        for (int i = 0; i < n; i++)
        {
            maxPro = max(maxPro, maxFuture[i] - prices[i]);
        }
        return maxPro;
    }

    // 3. OPTIMAL: Remember the lowest buying price seen so far on the fly
    // Time: O(N) | Space: O(1)
    int maxProfitOptimal(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxPro = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxPro;
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Buy at 1 (Day 2), Sell at 6 (Day 5) -> Profit: 5

    cout << "Brute   : " << obj.maxProfitBrute(prices) << "\n";
    cout << "Better  : " << obj.maxProfitBetter(prices) << " (O(N) Space)\n";
    cout << "Optimal : " << obj.maxProfitOptimal(prices) << " (O(1) Space)\n";

    return 0;
}