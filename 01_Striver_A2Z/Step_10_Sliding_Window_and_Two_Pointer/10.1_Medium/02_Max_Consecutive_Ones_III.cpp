#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Generate all subarrays and count zeros
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int longestOnesBrute(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int zeroCount = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                {
                    zeroCount++;
                }

                if (zeroCount <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                {
                    // Window is invalid, no need to expand further for this 'i'
                    break;
                }
            }
        }

        return maxLen;
    }

    // OPTIMAL: Sliding Window
    // Time Complexity: O(N) | Space Complexity: O(1)
    int longestOnesOptimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int maxLen = 0;

        while (right < n)
        {
            // Include the current element in the window
            if (nums[right] == 0)
            {
                zeroCount++;
            }

            // If the window is invalid, shrink from the left
            while (zeroCount > k)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }

            // At this point, zeroCount <= k, so the window is valid
            maxLen = max(maxLen, right - left + 1);

            // Expand to the next element
            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Brute Force: " << obj.longestOnesBrute(nums1, k1) << "\n";
    cout << "Optimal: " << obj.longestOnesOptimal(nums1, k1) << "\n";

    cout << "---\n";

    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    cout << "Optimal: " << obj.longestOnesOptimal(nums2, k2) << "\n";

    return 0;
}