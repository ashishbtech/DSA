#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Greedy choice from largest to smallest denomination
    // Time Complexity: O(N) where N is number of denominations | Space Complexity: O(1)
    vector<int> minCoins(int V)
    {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
        int n = coins.size();

        vector<int> result;

        // Traverse from the largest to the smallest
        for (int i = n - 1; i >= 0; i--)
        {

            // While the current coin can be used, subtract it from V
            while (V >= coins[i])
            {
                V -= coins[i];
                result.push_back(coins[i]);
            }

            // If V becomes 0, we can break early to save cycles
            if (V == 0)
            {
                break;
            }
        }

        return result;
    }
};

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    Solution obj;

    int V1 = 43;
    cout << "Value: 43\n";
    cout << "Coins Used: ";
    vector<int> res1 = obj.minCoins(V1);
    printArray(res1);
    cout << "Total Coins: " << res1.size() << "\n";
    cout << "---\n";

    int V2 = 1000;
    cout << "Value: 1000\n";
    cout << "Coins Used: ";
    vector<int> res2 = obj.minCoins(V2);
    printArray(res2);
    cout << "Total Coins: " << res2.size() << "\n";
    cout << "---\n";

    int V3 = 121;
    cout << "Value: 121\n";
    cout << "Coins Used: ";
    vector<int> res3 = obj.minCoins(V3);
    printArray(res3);
    cout << "Total Coins: " << res3.size() << "\n";

    return 0;
}