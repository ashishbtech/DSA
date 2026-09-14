#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Circular traversal using modulo
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    vector<int> nextGreaterElementsBrute(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);

        for (int i = 0; i < n; i++)
        {
            // Check the next (n-1) elements circularly
            for (int j = 1; j < n; j++)
            {
                int nextIndex = (i + j) % n;
                if (nums[nextIndex] > nums[i])
                {
                    nge[i] = nums[nextIndex];
                    break;
                }
            }
        }

        return nge;
    }

    // OPTIMAL: Imaginary array doubling + Monotonic Stack
    // Time Complexity: O(N) | Space Complexity: O(N) auxiliary
    vector<int> nextGreaterElementsOptimal(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Traverse virtually doubled array from right to left
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int currentIndex = i % n;

            // Pop elements smaller than or equal to current
            while (!st.empty() && st.top() <= nums[currentIndex])
            {
                st.pop();
            }

            // Only record answers for the actual array (indices 0 to N-1)
            if (i < n)
            {
                if (!st.empty())
                {
                    nge[i] = st.top();
                }
            }

            // Push current element for future comparisons
            st.push(nums[currentIndex]);
        }

        return nge;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 1};

    vector<int> bruteAns = obj.nextGreaterElementsBrute(nums);
    for (int x : bruteAns)
        cout << x << " ";
    cout << "\n";

    vector<int> optimalAns = obj.nextGreaterElementsOptimal(nums);
    for (int x : optimalAns)
        cout << x << " ";
    cout << "\n";

    return 0;
}