#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL APPROACH: One-Pass Linear Traversal
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
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

    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    cout << "Result 1: ";
    printIntervals(obj.insert(intervals1, newInterval1));

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    cout << "Result 2: ";
    printIntervals(obj.insert(intervals2, newInterval2));

    return 0;
}