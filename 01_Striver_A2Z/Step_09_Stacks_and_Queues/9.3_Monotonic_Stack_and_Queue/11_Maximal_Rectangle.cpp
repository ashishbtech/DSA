#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
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

public:
    // OPTIMAL: Histogram Reduction
    // Time Complexity: O(N * M) | Space Complexity: O(M)
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea = 0;

        vector<int> heights(cols, 0); // Histogram heights for the current row

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // If '1', increase height. If '0', reset height to 0.
                if (matrix[i][j] == '1')
                {
                    heights[j]++;
                }
                else
                {
                    heights[j] = 0;
                }
            }

            // Calculate max area for the histogram at the current row
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << "Maximal Rectangle Area: " << obj.maximalRectangle(matrix) << "\n";

    return 0;
}