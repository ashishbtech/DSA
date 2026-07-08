#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countPainters(vector<int> &boards, int maxTime)
    {
        int painters = 1;
        long long timeSpent = 0;

        for (int i = 0; i < boards.size(); i++)
        {
            if (timeSpent + boards[i] > maxTime)
            {
                painters++;
                timeSpent = boards[i];
            }
            else
            {
                timeSpent += boards[i];
            }
        }
        return painters;
    }

public:
    // 1. BRUTE FORCE: Linear Search
    // Time Complexity: O(N * (sum - max + 1)) | Space Complexity: O(1)
    int findLargestMinDistanceBrute(vector<int> &boards, int k)
    {
        int low = INT_MIN, high = 0;
        for (int i = 0; i < boards.size(); i++)
        {
            low = max(low, boards[i]);
            high += boards[i];
        }

        for (int maxTime = low; maxTime <= high; maxTime++)
        {
            if (countPainters(boards, maxTime) <= k)
            {
                return maxTime;
            }
        }
        return low;
    }

    // 2. OPTIMAL: Binary Search on Answers
    // Time Complexity: O(N * log(sum - max + 1)) | Space Complexity: O(1)
    int findLargestMinDistanceOptimal(vector<int> &boards, int k)
    {
        int low = INT_MIN, high = 0;
        for (int i = 0; i < boards.size(); i++)
        {
            low = max(low, boards[i]);
            high += boards[i];
        }

        int ans = low;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int paintersNeeded = countPainters(boards, mid);

            if (paintersNeeded <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    cout << "Brute Force : " << obj.findLargestMinDistanceBrute(boards, k) << "\n";
    cout << "Optimal     : " << obj.findLargestMinDistanceOptimal(boards, k) << "\n";

    return 0;
}