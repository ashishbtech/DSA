#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Nested loops
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    vector<int> nextGreaterElementBrute(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    nge[i] = arr[j];
                    break;
                }
            }
        }

        return nge;
    }

    // OPTIMAL: Monotonic Stack traversing right to left
    // Time Complexity: O(N) | Space Complexity: O(N) auxiliary
    vector<int> nextGreaterElementOptimal(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop elements that are smaller or equal to current element
            // They can never be the "Next Greater" for elements to the left
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }

            // If stack is not empty, the top is the Next Greater Element
            if (!st.empty())
            {
                nge[i] = st.top();
            }

            // Push current element to the stack
            st.push(arr[i]);
        }

        return nge;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    vector<int> bruteAns = obj.nextGreaterElementBrute(arr);
    for (int x : bruteAns)
        cout << x << " ";
    cout << "\n";

    vector<int> optimalAns = obj.nextGreaterElementOptimal(arr);
    for (int x : optimalAns)
        cout << x << " ";
    cout << "\n";

    return 0;
}