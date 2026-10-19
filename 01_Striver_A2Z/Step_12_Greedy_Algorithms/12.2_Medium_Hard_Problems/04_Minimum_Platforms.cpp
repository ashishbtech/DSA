#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL APPROACH: Sorting + Two Pointers
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int count = 1;
        int maxCount = 1;

        int i = 1;
        int j = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << obj.findPlatform(arr, dep) << "\n";

    return 0;
}