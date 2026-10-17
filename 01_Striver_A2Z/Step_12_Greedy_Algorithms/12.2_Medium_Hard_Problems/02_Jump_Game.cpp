#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Greedy Reachability Tracking
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool canJump(vector<int> &nums)
    {
        int maxReachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            if (i > maxReachable)
            {
                return false;
            }

            maxReachable = max(maxReachable, i + nums[i]);

            if (maxReachable >= n - 1)
            {
                return true;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "Can jump nums1? " << obj.canJump(nums1) << "\n";
    cout << "Can jump nums2? " << obj.canJump(nums2) << "\n";

    return 0;
}