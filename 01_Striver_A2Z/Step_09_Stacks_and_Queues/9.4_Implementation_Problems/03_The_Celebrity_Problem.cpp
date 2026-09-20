#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Indegree and Outdegree arrays
    // Time Complexity: O(N^2) | Space Complexity: O(N)
    int celebrityBrute(vector<vector<int>> &M, int n)
    {
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
            {
                return i;
            }
        }

        return -1;
    }

    // BETTER: Stack-based Elimination
    // Time Complexity: O(N) | Space Complexity: O(N)
    int celebrityBetter(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // Step 1: Eliminate until 1 person is left
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (M[a][b] == 1)
            {
                // 'a' knows 'b', so 'a' cannot be celebrity
                st.push(b);
            }
            else
            {
                // 'a' does not know 'b', so 'b' cannot be celebrity
                st.push(a);
            }
        }

        int potential = st.top();

        // Step 2: Verify the potential celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != potential)
            {
                // A celebrity must not know anyone, and everyone must know them
                if (M[potential][i] == 1 || M[i][potential] == 0)
                {
                    return -1;
                }
            }
        }

        return potential;
    }

    // OPTIMAL: Two Pointers
    // Time Complexity: O(N) | Space Complexity: O(1)
    int celebrityOptimal(vector<vector<int>> &M, int n)
    {
        int top = 0;
        int down = n - 1;

        // Step 1: Eliminate using two pointers
        while (top < down)
        {
            if (M[top][down] == 1)
            {
                top++; // top knows down, top is not celebrity
            }
            else
            {
                down--; // top doesn't know down, down is not celebrity
            }
        }

        int potential = top; // or down, since they are equal

        // Step 2: Verify the potential celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != potential)
            {
                // A celebrity must not know anyone, and everyone must know them
                if (M[potential][i] == 1 || M[i][potential] == 0)
                {
                    return -1;
                }
            }
        }

        return potential;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> M1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    int n1 = 3;

    cout << "Brute Force: " << obj.celebrityBrute(M1, n1) << "\n";
    cout << "Better: " << obj.celebrityBetter(M1, n1) << "\n";
    cout << "Optimal: " << obj.celebrityOptimal(M1, n1) << "\n";

    vector<vector<int>> M2 = {
        {0, 1},
        {1, 0}};
    int n2 = 2;

    cout << "Optimal (No Celeb): " << obj.celebrityOptimal(M2, n2) << "\n";

    return 0;
}