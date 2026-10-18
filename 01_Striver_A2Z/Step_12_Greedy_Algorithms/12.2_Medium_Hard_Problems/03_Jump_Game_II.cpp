#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Greedy Window/Range Tracking
    // Time Complexity: O(N) | Space Complexity: O(1)
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};

    cout << "Minimum jumps: " << obj.jump(nums1) << "\n";
    cout << "Minimum jumps: " << obj.jump(nums2) << "\n";

    return 0;
}