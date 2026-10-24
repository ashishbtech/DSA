#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    // OPTIMAL APPROACH: Greedy Sorting by End Time
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), comp);

        int count = 0;
        int limit = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < limit)
            {

                count++;
            }
            else
            {

                limit = intervals[i][1];
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << obj.eraseOverlapIntervals(intervals1) << "\n";

    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << obj.eraseOverlapIntervals(intervals2) << "\n";

    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};
    cout << obj.eraseOverlapIntervals(intervals3) << "\n";

    return 0;
}