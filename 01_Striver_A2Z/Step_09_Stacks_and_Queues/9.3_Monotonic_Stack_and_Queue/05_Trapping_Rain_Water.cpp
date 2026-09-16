#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Nested loops for every element
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int trapBrute(vector<int> &height)
    {
        int n = height.size();
        int totalWater = 0;

        for (int i = 0; i < n; i++)
        {
            int leftMax = 0, rightMax = 0;

            // Find max height on the left
            for (int j = i; j >= 0; j--)
            {
                leftMax = max(leftMax, height[j]);
            }
            // Find max height on the right
            for (int j = i; j < n; j++)
            {
                rightMax = max(rightMax, height[j]);
            }

            totalWater += min(leftMax, rightMax) - height[i];
        }
        return totalWater;
    }

    // BETTER: Prefix and Suffix Arrays
    // Time Complexity: O(N) | Space Complexity: O(N)
    int trapBetter(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++)
        {
            totalWater += min(prefix[i], suffix[i]) - height[i];
        }

        return totalWater;
    }

    // OPTIMAL: Two Pointers
    // Time Complexity: O(N) | Space Complexity: O(1)
    int trapOptimal(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left]; // Update left max
                }
                else
                {
                    totalWater += leftMax - height[left]; // Trap water
                }
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right]; // Update right max
                }
                else
                {
                    totalWater += rightMax - height[right]; // Trap water
                }
                right--;
            }
        }
        return totalWater;
    }
};

int main()
{
    Solution obj;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Brute Force: " << obj.trapBrute(height) << "\n";
    cout << "Better: " << obj.trapBetter(height) << "\n";
    cout << "Optimal: " << obj.trapOptimal(height) << "\n";

    return 0;
}