#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to count subarrays with AT MOST 'k' distinct integers
    int subarraysWithAtMostKDistinct(vector<int> &nums, int k)
    {
        if (k == 0)
            return 0;

        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int, int> freqMap;

        while (right < n)
        {
            // Include current element
            freqMap[nums[right]]++;

            // Shrink window if distinct elements exceed k
            while (freqMap.size() > k)
            {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0)
                {
                    freqMap.erase(nums[left]);
                }
                left++;
            }

            // Number of valid subarrays ending at 'right' is the window length
            count += (right - left + 1);
            right++;
        }

        return count;
    }

public:
    // BRUTE FORCE: Nested loops to check distinct integers in all subarrays
    // Time Complexity: O(N^2) | Space Complexity: O(K)
    int subarraysWithKDistinctBrute(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> freqMap;
            for (int j = i; j < n; j++)
            {
                freqMap[nums[j]]++;

                if (freqMap.size() == k)
                {
                    count++;
                }
                else if (freqMap.size() > k)
                {
                    break;
                }
            }
        }
        return count;
    }

    // OPTIMAL: Exactly(K) = AtMost(K) - AtMost(K - 1)
    // Time Complexity: O(N) | Space Complexity: O(N)
    int subarraysWithKDistinctOptimal(vector<int> &nums, int k)
    {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << "Array: [1, 2, 1, 2, 3] | k: 2\n";
    cout << "Brute Force: " << obj.subarraysWithKDistinctBrute(nums1, k1) << "\n";
    cout << "Optimal: " << obj.subarraysWithKDistinctOptimal(nums1, k1) << "\n";

    cout << "---\n";

    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    cout << "Array: [1, 2, 1, 3, 4] | k: 3\n";
    cout << "Optimal: " << obj.subarraysWithKDistinctOptimal(nums2, k2) << "\n";

    return 0;
}