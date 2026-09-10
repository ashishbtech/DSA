#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to return precedence of operators
    int precedence(char ch)
    {
        if (ch == '^')
            return 3;
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }

public:
    // OPTIMAL: Stack-based parsing
    // Time Complexity: O(N) | Space Complexity: O(N) for stack and result string
    string infixToPostfix(string s)
    {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            // 1. If operand, add directly to result
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                ans += c;
            }
            // 2. If left parenthesis, push to stack
            else if (c == '(')
            {
                st.push('(');
            }
            // 3. If right parenthesis, pop until left parenthesis
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // Pop the '('
            }
            // 4. If an operator
            else
            {
                while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
                {
                    // Right associativity check for '^'
                    // If current is '^' and top is '^', we don't pop because '^' evaluates right-to-left
                    if (c == '^' && st.top() == '^')
                    {
                        break;
                    }
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // 5. Pop all remaining operators from the stack
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    cout << obj.infixToPostfix(exp) << "\n";
    // Expected output: abcd^e-fgh*+^*+i-

    return 0;
}