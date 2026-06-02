/*
LeetCode 2144. Minimum Cost of Buying Candies With Discount
Date: 2026-06-01
Difficulty: Easy
Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

Approach:
1. Sort candies in descending order.
2. For every group of 3 candies, the cheapest one becomes free.
3. Add the cost of candies whose positions are not multiples of 3.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding sorting space)
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        
        int ans = 0;
        
        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) { // every third candy is free
                ans += cost[i];
            }
        }
        
        return ans;
    }
};