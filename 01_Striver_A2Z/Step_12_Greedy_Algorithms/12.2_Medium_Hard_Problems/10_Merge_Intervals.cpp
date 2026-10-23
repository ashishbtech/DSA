#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL APPROACH: Sorting + Single Pass Merge
    // Time Complexity: O(N log N) + O(N) | Space Complexity: O(N)
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 0)
            return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++)
        {

            if (intervals[i][0] <= ans.back()[1])
            {

                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {

                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

void printIntervals(const vector<vector<int>> &intervals)
{
    cout << "[";
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i != intervals.size() - 1)
            cout << ",";
    }
    cout << "]\n";
}

int main()
{
    Solution obj;

    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Input: [[1,3],[2,6],[8,10],[15,18]]\n";
    cout << "Merged: ";
    printIntervals(obj.merge(intervals1));

    cout << "---\n";

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    cout << "Input: [[1,4],[4,5]]\n";
    cout << "Merged: ";
    printIntervals(obj.merge(intervals2));

    return 0;
}