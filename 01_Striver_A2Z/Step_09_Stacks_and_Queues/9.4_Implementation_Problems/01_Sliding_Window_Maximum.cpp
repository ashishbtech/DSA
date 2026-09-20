#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Nested loops for each window
    // Time Complexity: O(N * K) | Space Complexity: O(1)
    vector<int> maxSlidingWindowBrute(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++)
        {
            int maxVal = nums[i];
            for (int j = i; j < i + k; j++)
            {
                maxVal = max(maxVal, nums[j]);
            }
            ans.push_back(maxVal);
        }

        return ans;
    }

    // OPTIMAL: Monotonic Deque
    // Time Complexity: O(N) | Space Complexity: O(K)
    vector<int> maxSlidingWindowOptimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; // Stores indices

        for (int i = 0; i < n; i++)
        {
            // 1. Remove elements that are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // 2. Remove elements that are smaller than the current element
            // They are useless because the current element is bigger and will stay longer
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            // 3. Push the current index
            dq.push_back(i);

            // 4. If the window has hit size k, record the maximum (which is at the front)
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Brute Force: ";
    vector<int> bruteAns = obj.maxSlidingWindowBrute(nums, k);
    for (int x : bruteAns)
        cout << x << " ";
    cout << "\n";

    cout << "Optimal: ";
    vector<int> optimalAns = obj.maxSlidingWindowOptimal(nums, k);
    for (int x : optimalAns)
        cout << x << " ";
    cout << "\n";

    return 0;
}