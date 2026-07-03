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
    // 1. BRUTE FORCE: Linear scan from left to right
    // Time Complexity: O(N) | Space Complexity: O(1)
    pair<int, int> firstAndLastBrute(vector<int> &arr, int target)
    {
        int first = -1, last = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        return {first, last};
    }

    // 2. OPTIMAL: Two separate Binary Searches
    // Time Complexity: O(2 * log N) -> O(log N) | Space Complexity: O(1)
    pair<int, int> firstAndLastOptimal(vector<int> &arr, int target)
    {
        int first = getFirst(arr, target);

        if (first == -1)
            return {-1, -1};

        int last = getLast(arr, target);
        return {first, last};
    }


  

};

int main()
{
    Solution obj;
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int target = 8;

    pair<int, int> brute = obj.firstAndLastBrute(arr, target);
    cout << "1. Brute Force : [ " << brute.first << ", " << brute.second << " ]\n";

    pair<int, int> opt = obj.firstAndLastOptimal(arr, target);
    cout << "2. Optimal     : [ " << opt.first << ", " << opt.second << " ]\n";

    return 0;
}