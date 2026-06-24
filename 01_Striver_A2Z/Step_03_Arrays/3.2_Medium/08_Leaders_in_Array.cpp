#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Double nested loop checking every element against everything to its right
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    vector<int> leadersBrute(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            bool leader = true;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] >= arr[i])
                {
                    leader = false;
                    break;
                }
            }
            if (leader)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }

    // 2. BETTER: Precompute a Suffix Max array from right to left, then evaluate forward
    // Time Complexity: O(2N) ≈ O(N) | Space Complexity: O(N) auxiliary space
    vector<int> leadersBetter(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        vector<int> suffixMax(n, 0);
        vector<int> ans;

        // Build suffix max looking right-to-left
        suffixMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }

        // Forward pass: if an element matches or exceeds the suffix max bounds appropriately
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > suffixMax[i + 1])
            {
                ans.push_back(arr[i]);
            }
        }
        ans.push_back(arr[n - 1]); // Rightmost is always a leader

        return ans;
    }

    // 3. OPTIMAL: Scan directly from right to left, tracking the running max on the fly
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary space (output vector independent)
    vector<int> leadersOptimal(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        int maxFromRight = INT_MIN;

        // Scan backwards to naturally look at the right hand side
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > maxFromRight)
            {
                ans.push_back(arr[i]);
                maxFromRight = arr[i]; // Update the barrier
            }
        }

        // Since we scanned backwards, leaders are collected in reverse order.
        // Reversing the final answer takes O(N) time.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {16, 17, 4, 3, 5, 2}; // Leaders are 17, 5, 2

    cout << "--- Problem 8: Leaders in an Array ---\n\n";

    vector<int> r1 = obj.leadersBrute(arr);
    cout << "Brute   : ";
    for (int x : r1)
        cout << x << " ";
    cout << "\n";

    vector<int> r2 = obj.leadersBetter(arr);
    cout << "Better  : ";
    for (int x : r2)
        cout << x << " ";
    cout << "\n";

    vector<int> r3 = obj.leadersOptimal(arr);
    cout << "Optimal : ";
    for (int x : r3)
        cout << x << " ";
    cout << "\n";

    return 0;
}