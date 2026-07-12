#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BETTER: Using a Stack to track primitive boundaries
    // Time Complexity: O(N) | Space Complexity: O(N) for the stack
    string removeOuterParenthesesStack(string s)
    {
        stack<char> st;
        string result = "";

        for (char c : s)
        {
            if (c == '(')
            {
                // If stack already has elements, this is NOT an outermost '('
                if (!st.empty())
                {
                    result += c;
                }
                st.push(c);
            }
            else
            {
                st.pop();
                // If stack still has elements after popping, this is NOT an outermost ')'
                if (!st.empty())
                {
                    result += c;
                }
            }
        }
        return result;
    }

    // 2. OPTIMAL: Using a balance counter (O(1) Auxiliary Space)
    // Time Complexity: O(N) | Space Complexity: O(1) (excluding result string)
    string removeOuterParenthesesOptimal(string s)
    {
        string result = "";
        int balance = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                // Any open parenthesis seen when balance > 0 is an inner one
                if (balance > 0)
                {
                    result += c;
                }
                balance++;
            }
            else
            {
                balance--;
                // Any close parenthesis that leaves balance > 0 is an inner one
                if (balance > 0)
                {
                    result += c;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution obj;
    string s = "(()())(())";

    cout << "Stack Approach   : " << obj.removeOuterParenthesesStack(s) << "\n";
    cout << "Optimal Approach : " << obj.removeOuterParenthesesOptimal(s) << "\n";

    return 0;
}