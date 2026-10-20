#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL APPROACH: Two-Pass Greedy
    // Time Complexity: O(N) | Space Complexity: O(N)
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // 1. Left-to-Right Pass: Check against the left neighbor
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 2. Right-to-Left Pass: Check against the right neighbor
        // We can optimize by calculating the sum in the same loop
        int sum = candies[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }

        return sum;
    }
};

int main()
{
    Solution obj;

    vector<int> ratings1 = {1, 0, 2};
    cout << obj.candy(ratings1) << "\n";

    vector<int> ratings2 = {1, 2, 2};
    cout << obj.candy(ratings2) << "\n";

    return 0;
}