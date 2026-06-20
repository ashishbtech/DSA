// Logic: If the array contains ONLY positives/zeros, a two-pointer sliding window is optimal (O(N) time, O(1) space).
// If the array contains NEGATIVES, the sliding window breaks, and you must fall back to tracking prefix sums in an STL map (O(N) time, O(N) space).

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Optimal for POSITIVES only: Two-pointer/Sliding Window
    int longestSubarrayWithSumK_Positives(vector<int> &arr, long long k)
    {
        int left = 0, right = 0;
        long long currentSum = 0;
        int maxLen = 0;
        int n = arr.size();

        while (right < n)
        {
            currentSum += arr[right];

            // Shrink window if sum exceeds k
            while (left <= right && currentSum > k)
            {
                currentSum -= arr[left];
                left++;
            }

            if (currentSum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }

    // Optimal for POSITIVES + NEGATIVES: Prefix Sum Hashing
    int longestSubarrayWithSumK_All(vector<int> &arr, long long k)
    {
        unordered_map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            long long rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Only store the sum if it doesn't exist to maintain the furthest left index
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution obj;
    vector<int> posArr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    cout << "Longest Subarray (Positives only): " << obj.longestSubarrayWithSumK_Positives(posArr, 3) << endl;

    vector<int> mixArr = {-1, 1, 1, -1, 1};
    cout << "Longest Subarray (With Negatives): " << obj.longestSubarrayWithSumK_All(mixArr, 1) << endl;

    return 0;
}