#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countSubarrays(vector<int> &nums, int maxSumAllowed)
    {
        int subarrays = 1;
        long long currentSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (currentSum + nums[i] > maxSumAllowed)
            {
                subarrays++;
                currentSum = nums[i];
            }
            else
            {
                currentSum += nums[i];
            }
        }
        return subarrays;
    }

public:
    // 1. BRUTE FORCE: Linear Search
    // Time Complexity: O(N * (sum - max + 1)) | Space Complexity: O(1)
    int splitArrayBrute(vector<int> &nums, int k)
    {
        int low = INT_MIN, high = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        for (int maxSum = low; maxSum <= high; maxSum++)
        {
            if (countSubarrays(nums, maxSum) <= k)
            {
                return maxSum;
            }
        }
        return low;
    }

    // 2. OPTIMAL: Binary Search on Answers
    // Time Complexity: O(N * log(sum - max + 1)) | Space Complexity: O(1)
    int splitArrayOptimal(vector<int> &nums, int k)
    {
        int low = INT_MIN, high = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        int ans = low;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int partitionsNeeded = countSubarrays(nums, mid);

            if (partitionsNeeded <= k)
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
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << "Brute Force : " << obj.splitArrayBrute(nums, k) << "\n";
    cout << "Optimal     : " << obj.splitArrayOptimal(nums, k) << "\n";

    return 0;
}