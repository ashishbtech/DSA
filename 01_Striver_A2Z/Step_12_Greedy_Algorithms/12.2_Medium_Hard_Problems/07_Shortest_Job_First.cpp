#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL APPROACH: Greedy Sorting
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    long long solve(vector<int> &bt)
    {
        // Step 1: Sort burst times in ascending order
        sort(bt.begin(), bt.end());

        long long waitTime = 0;
        long long totalWaitTime = 0;
        int n = bt.size();

        // Step 2: Accumulate waiting times
        for (int i = 0; i < n; i++)
        {
            totalWaitTime = totalWaitTime + waitTime;

            waitTime = waitTime + bt[i];
        }

        return totalWaitTime / n;
    }
};

int main()
{
    Solution obj;

    vector<int> bt1 = {4, 3, 7, 1, 2};
    cout << obj.solve(bt1) << "\n";

    vector<int> bt2 = {1, 2, 3, 4};
    cout << obj.solve(bt2) << "\n";

    return 0;
}