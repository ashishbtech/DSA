#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countStudents(vector<int> &arr, int maxPagesAllowed)
    {
        int students = 1;
        long long pagesStudent = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (pagesStudent + arr[i] > maxPagesAllowed)
            {
                students++;
                pagesStudent = arr[i];
            }
            else
            {
                pagesStudent += arr[i];
            }
        }
        return students;
    }

public:
    // 1. BRUTE FORCE: Linear Search on the Answer Space
    // Time Complexity: O(N * (sum - max + 1)) | Space Complexity: O(1)
    int findPagesBrute(vector<int> &arr, int n, int m)
    {
        if (m > n)
            return -1;

        int low = INT_MIN;
        int high = 0;

        for (int i = 0; i < n; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }

        for (int limit = low; limit <= high; limit++)
        {
            if (countStudents(arr, limit) <= m)
            {
                return limit;
            }
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search on Answers (Min-Max Partition)
    // Time Complexity: O(N * log(sum - max + 1)) | Space Complexity: O(1)
    int findPagesOptimal(vector<int> &arr, int n, int m)
    {
        if (m > n)
            return -1;

        int low = INT_MIN;
        int high = 0;

        for (int i = 0; i < n; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int studentsNeeded = countStudents(arr, mid);

            if (studentsNeeded <= m)
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
    vector<int> arr = {12, 34, 67, 90};
    int m = 2;

    cout << "Brute Force : " << obj.findPagesBrute(arr, arr.size(), m) << "\n";
    cout << "Optimal     : " << obj.findPagesOptimal(arr, arr.size(), m) << "\n";

    return 0;
}