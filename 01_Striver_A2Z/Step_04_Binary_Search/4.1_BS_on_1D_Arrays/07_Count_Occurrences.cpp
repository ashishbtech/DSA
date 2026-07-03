#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getFirst(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return first;
    }

    int getLast(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return last;
    }

public:
    // OPTIMAL: Two Binary Searches
    // Time Complexity: O(2 * log N) -> O(log N) | Space Complexity: O(1)
    int countOccurrences(vector<int> &arr, int target)
    {
        int first = getFirst(arr, target);

        if (first == -1)
            return 0;

        int last = getLast(arr, target);

        return (last - first) + 1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int target = 8;

    cout << "Occurrences : " << obj.countOccurrences(arr, target) << "\n";

    return 0;
}