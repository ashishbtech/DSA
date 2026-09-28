#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Physically simulate the k-bit flips
    // Time Complexity: O(N * K) | Space Complexity: O(N) auxiliary copy
    int minKBitFlipsBrute(vector<int> &nums, int k)
    {
        int n = nums.size();
        int flips = 0;
        vector<int> temp = nums;

        for (int i = 0; i < n; i++)
        {
            if (temp[i] == 0)
            {

                if (i + k > n)
                {
                    return -1;
                }

                for (int j = i; j < i + k; j++)
                {
                    temp[j] ^= 1;
                }
                flips++;
            }
        }

        return flips;
    }

    // OPTIMAL: Sliding Window using a Queue to track active overlapping flips
    // Time Complexity: O(N) | Space Complexity: O(K)
    int minKBitFlipsOptimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        queue<int> activeFlips;
        int flipCount = 0;

        for (int i = 0; i < n; i++)
        {

            if (!activeFlips.empty() && i - activeFlips.front() >= k)
            {
                activeFlips.pop();
            }

            if ((nums[i] + activeFlips.size()) % 2 == 0)
            {

                if (i + k > n)
                {
                    return -1;
                }

                activeFlips.push(i);
                flipCount++;
            }
        }

        return flipCount;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {0, 1, 0};
    int k1 = 1;
    cout << "Array: [0, 1, 0] | k: 1\n";
    cout << "Brute Force: " << obj.minKBitFlipsBrute(nums1, k1) << "\n";
    cout << "Optimal: " << obj.minKBitFlipsOptimal(nums1, k1) << "\n";

    cout << "---\n";

    vector<int> nums2 = {1, 1, 0};
    int k2 = 2;
    cout << "Array: [1, 1, 0] | k: 2\n";
    cout << "Optimal: " << obj.minKBitFlipsOptimal(nums2, k2) << "\n";

    cout << "---\n";

    vector<int> nums3 = {0, 0, 0, 1, 0, 1, 1, 0};
    int k3 = 3;
    cout << "Array: [0, 0, 0, 1, 0, 1, 1, 0] | k: 3\n";
    cout << "Optimal: " << obj.minKBitFlipsOptimal(nums3, k3) << "\n";

    return 0;
}