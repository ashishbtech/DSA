#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
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
    // OPTIMAL: Reverse -> Modified Postfix -> Reverse
    // Time Complexity: O(N) | Space Complexity: O(N)
    string infixToPrefix(string s)
    {
        // 1. Reverse the string and swap brackets
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                s[i] = ')';
            }
            else if (s[i] == ')')
            {
                s[i] = '(';
            }
        }

        string ans = "";
        stack<char> st;

        // 2. Apply modified Infix to Postfix logic
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            // If operand, add directly to result
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                ans += c;
            }
            // If left parenthesis, push to stack
            else if (c == '(')
            {
                st.push('(');
            }
            // If right parenthesis, pop until left parenthesis
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
            // If an operator
            else
            {
                while (!st.empty() && st.top() != '(')
                {
                    // Pop if top has strictly greater precedence
                    if (precedence(c) < precedence(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }
                    // Pop if equal precedence ONLY for '^' (due to reversed associativity)
                    else if (precedence(c) == precedence(st.top()) && c == '^')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                st.push(c);
            }
        }

        // Pop all remaining operators from the stack
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // 3. Reverse the final postfix result to get the prefix expression
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    string exp = "(A+B)*C-(D-E)*(F+G)";

    cout << obj.infixToPrefix(exp) << "\n";
    // Expected output: -*+ABC*-DE+FG

    return 0;
}