#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Using a physical stack to track open brackets
    // Time Complexity: O(N) | Space Complexity: O(N) for stack storage
    int maxDepthStack(string s)
    {
        stack<char> st;
        int maxDepth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                st.push(c);

                maxDepth = max(maxDepth, (int)st.size());
            }
            else if (c == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }

        return maxDepth;
    }

    // 2. OPTIMAL: O(1) Space using an integer balance counter
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    int maxDepthOptimal(string s)
    {
        int currentDepth = 0;
        int maxDepth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                currentDepth++;

                maxDepth = max(maxDepth, currentDepth);
            }
            else if (c == ')')
            {
                currentDepth--;
            }
        }

        return maxDepth;
    }
};

int main()
{
    Solution obj;
    string s1 = "(1+(2*3)+((8)/4))+1"; // Deepest is around '8' -> depth 3
    string s2 = "(1)+((2))+(((3)))";   // Deepest is around '3' -> depth 3
    string s3 = "1+2+3-4";             // No brackets -> depth 0

    cout << "Stack Approach   (s1) : Depth " << obj.maxDepthStack(s1) << "\n";
    cout << "Optimal Approach (s2) : Depth " << obj.maxDepthOptimal(s2) << "\n";
    cout << "Optimal Approach (s3) : Depth " << obj.maxDepthOptimal(s3) << "\n";

    return 0;
}