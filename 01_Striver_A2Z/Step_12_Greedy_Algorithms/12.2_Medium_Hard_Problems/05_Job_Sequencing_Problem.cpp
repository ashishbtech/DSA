#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    // OPTIMAL APPROACH: Greedy + Array Hashing
    // Time Complexity: O(N log N + N*M) | Space Complexity: O(M)
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0;
        int jobProfit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {countJobs, jobProfit};
    }
};

int main()
{
    Solution obj;

    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = obj.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}