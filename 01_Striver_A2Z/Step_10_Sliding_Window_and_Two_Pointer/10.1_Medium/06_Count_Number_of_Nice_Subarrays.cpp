#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to count subarrays with AT MOST 'k' odd numbers
    int numberOfSubarraysAtMost(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;

        int left = 0;
        int right = 0;
        int oddCount = 0;
        int totalCount = 0;
        int n = nums.size();

        while (right < n)
        {
            // Treat odd numbers as 1 and even numbers as 0
            if (nums[right] % 2 != 0)
            {
                oddCount++;
            }

            // Shrink window if the odd count exceeds k
            while (oddCount > k)
            {
                if (nums[left] % 2 != 0)
                {
                    oddCount--;
                }
                left++;
            }

            // Number of valid subarrays ending at 'right' is the window length
            totalCount += (right - left + 1);

            right++;
        }

        return totalCount;
    }

public:
    // BRUTE FORCE: Nested loops to count odd numbers in all subarrays
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int numberOfSubarraysBrute(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int oddCount = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 != 0)
                {
                    oddCount++;
                }

                if (oddCount == k)
                {
                    count++;
                }
                else if (oddCount > k)
                {
                    break;
                }
            }
        }
        return count;
    }

    // OPTIMAL: Exactly(K) = AtMost(K) - AtMost(K - 1) using Sliding Window
    // Time Complexity: O(N) | Space Complexity: O(1)
    int numberOfSubarraysOptimal(vector<int> &nums, int k)
    {
        return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << "Array: [1, 1, 2, 1, 1] | k: 3\n";
    cout << "Brute Force: " << obj.numberOfSubarraysBrute(nums1, k1) << "\n";
    cout << "Optimal: " << obj.numberOfSubarraysOptimal(nums1, k1) << "\n";

    cout << "---\n";

    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    cout << "Array: [2, 4, 6] | k: 1\n";
    cout << "Optimal: " << obj.numberOfSubarraysOptimal(nums2, k2) << "\n";

    cout << "---\n";

    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k3 = 2;
    cout << "Array: [2, 2, 2, 1, 2, 2, 1, 2, 2, 2] | k: 2\n";
    cout << "Optimal: " << obj.numberOfSubarraysOptimal(nums3, k3) << "\n";

    return 0;
}