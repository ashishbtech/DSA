#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to count subarrays with sum AT MOST 'goal'
    int numSubarraysWithSumAtMost(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0; // Binary array sum cannot be negative

        int left = 0;
        int right = 0;
        int currentSum = 0;
        int totalCount = 0;
        int n = nums.size();

        while (right < n)
        {
            currentSum += nums[right];

            // Shrink window if the sum exceeds the goal
            while (currentSum > goal)
            {
                currentSum -= nums[left];
                left++;
            }

            // Number of valid subarrays ending at 'right' is the window length
            totalCount += (right - left + 1);

            right++;
        }

        return totalCount;
    }

public:
    // BRUTE FORCE: Nested loops to check all subarrays
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int numSubarraysWithSumBrute(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int currentSum = 0;
            for (int j = i; j < n; j++)
            {
                currentSum += nums[j];
                if (currentSum == goal)
                {
                    count++;
                }
                else if (currentSum > goal)
                {
                    break;
                }
            }
        }
        return count;
    }

    // OPTIMAL: Exactly(K) = AtMost(K) - AtMost(K - 1) using Sliding Window
    // Time Complexity: O(N) | Space Complexity: O(1)
    int numSubarraysWithSumOptimal(vector<int> &nums, int goal)
    {
        return numSubarraysWithSumAtMost(nums, goal) - numSubarraysWithSumAtMost(nums, goal - 1);
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Array: [1, 0, 1, 0, 1] | Goal: 2\n";
    cout << "Brute Force: " << obj.numSubarraysWithSumBrute(nums1, goal1) << "\n";
    cout << "Optimal: " << obj.numSubarraysWithSumOptimal(nums1, goal1) << "\n";

    cout << "---\n";

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Array: [0, 0, 0, 0, 0] | Goal: 0\n";
    cout << "Optimal: " << obj.numSubarraysWithSumOptimal(nums2, goal2) << "\n";

    return 0;
}