#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // STANDARD APPROACH: Calculate on the fly
    // Time Complexity: O(Q * N) | Space Complexity: O(1) auxiliary
    vector<int> countNGEsOnTheFly(vector<int> &arr, vector<int> &queries)
    {
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i];
            int count = 0;

            // Count elements strictly greater to the right
            for (int j = index + 1; j < n; j++)
            {
                if (arr[j] > arr[index])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }

        return ans;
    }

    // PRECOMPUTATION APPROACH: Best when Q is extremely large
    // Time Complexity: O(N^2 + Q) | Space Complexity: O(N) auxiliary
    vector<int> countNGEsPrecomputed(vector<int> &arr, vector<int> &queries)
    {
        int n = arr.size();
        vector<int> precomputedCount(n, 0);

        // O(N^2) Precomputation
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    count++;
                }
            }
            precomputedCount[i] = count;
        }

        // O(Q) Query Answering
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(precomputedCount[queries[i]]);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> queries = {0, 2, 6};

    vector<int> ans1 = obj.countNGEsOnTheFly(arr, queries);
    for (int x : ans1)
        cout << x << " ";
    cout << "\n";

    vector<int> ans2 = obj.countNGEsPrecomputed(arr, queries);
    for (int x : ans2)
        cout << x << " ";
    cout << "\n";

    return 0;
}