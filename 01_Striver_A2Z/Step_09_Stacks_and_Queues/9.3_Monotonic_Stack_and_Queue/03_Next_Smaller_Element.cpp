#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Nested loops looking for the first smaller element
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    vector<int> nextSmallerElementBrute(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                {
                    nse[i] = arr[j];
                    break;
                }
            }
        }

        return nse;
    }

    // OPTIMAL: Monotonic Stack traversing right to left
    // Time Complexity: O(N) | Space Complexity: O(N) auxiliary
    vector<int> nextSmallerElementOptimal(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop elements that are greater than or equal to current element
            // They can never be the "Next Smaller" for elements to the left
            while (!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }

            // If stack is not empty, the top is the Next Smaller Element
            if (!st.empty())
            {
                nse[i] = st.top();
            }

            // Push current element to the stack
            st.push(arr[i]);
        }

        return nse;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 8, 5, 2, 25};

    vector<int> bruteAns = obj.nextSmallerElementBrute(arr);
    for (int x : bruteAns)
        cout << x << " ";
    cout << "\n";

    vector<int> optimalAns = obj.nextSmallerElementOptimal(arr);
    for (int x : optimalAns)
        cout << x << " ";
    cout << "\n";

    return 0;
}