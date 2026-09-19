#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Expand outwards for each bar
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int largestRectangleAreaBrute(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int minHeight = heights[i];
            for (int j = i; j < n; j++)
            {
                minHeight = min(minHeight, heights[j]);
                int width = j - i + 1;
                maxArea = max(maxArea, minHeight * width);
            }
        }
        return maxArea;
    }

    // BETTER: Precompute PSE and NSE using Monotonic Stacks
    // Time Complexity: O(N) | Space Complexity: O(N)
    int largestRectangleAreaBetter(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;

        // Find Previous Smaller Element indices
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop(); // Clear stack

        // Find Next Smaller Element indices
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }

    // OPTIMAL: Single Pass Stack Calculation
    // Time Complexity: O(N) | Space Complexity: O(N)
    int largestRectangleAreaOptimal(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            // We use i == n to force remaining elements in the stack to pop
            // Assume the height at index 'n' is 0, which is smaller than everything
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main()
{
    Solution obj;
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Brute Force: " << obj.largestRectangleAreaBrute(heights) << "\n";
    cout << "Better: " << obj.largestRectangleAreaBetter(heights) << "\n";
    cout << "Optimal: " << obj.largestRectangleAreaOptimal(heights) << "\n";

    return 0;
}