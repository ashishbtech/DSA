#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
    int start;
    int end;
    int pos;
};

class Solution
{
private:
    // Custom comparator to sort meetings by end time
    static bool comp(Meeting m1, Meeting m2)
    {
        // If end times are different, sort strictly by earliest end time
        if (m1.end < m2.end)
            return true;
        if (m1.end > m2.end)
            return false;

        // If end times are exactly the same, tie-break by original position
        return m1.pos < m2.pos;
    }

public:
    // OPTIMAL: Greedy Sorting by End Time
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    int maxMeetings(int start[], int end[], int n)
    {
        // Step 1: Initialize the array of Meeting structs
        vector<Meeting> meet(n);
        for (int i = 0; i < n; i++)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        // Step 2: Sort the meetings using our custom comparator
        sort(meet.begin(), meet.end(), comp);

        // Step 3: Iterate and greedily select meetings
        int limit = meet[0].end;
        int count = 1;
        vector<int> order;
        order.push_back(meet[0].pos);

        for (int i = 1; i < n; i++)
        {
            if (meet[i].start > limit)
            {
                limit = meet[i].end;
                count++;
                order.push_back(meet[i].pos);
            }
        }

        // print the order of meetings attended for clarity
        cout << "Meeting Order (1-based index): ";
        for (int p : order)
        {
            cout << p << " ";
        }
        cout << "\n";

        return count;
    }
};

int main()
{
    Solution obj;

    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    cout << "Start times: [1, 3, 0, 5, 8, 5]\n";
    cout << "End times:   [2, 4, 6, 7, 9, 9]\n";
    cout << "Maximum Meetings: " << obj.maxMeetings(start1, end1, n1) << "\n";
    cout << "---\n";

    // Test Case 2
    int start2[] = {10, 12, 20};
    int end2[] = {20, 25, 30};
    int n2 = sizeof(start2) / sizeof(start2[0]);
    cout << "Start times: [10, 12, 20]\n";
    cout << "End times:   [20, 25, 30]\n";
    cout << "Maximum Meetings: " << obj.maxMeetings(start2, end2, n2) << "\n";

    return 0;
}