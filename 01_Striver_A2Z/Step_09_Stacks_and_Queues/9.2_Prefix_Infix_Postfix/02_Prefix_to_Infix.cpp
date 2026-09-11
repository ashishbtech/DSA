#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isOperand(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

public:
    // OPTIMAL: Stack-based string building (Right to Left)
    // Time Complexity: O(N) | Space Complexity: O(N)
    string prefixToInfix(string s)
    {
        stack<string> st;

        // Traverse the prefix expression from right to left
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (isOperand(c))
            {
                // Convert char to string and push to stack
                st.push(string(1, c));
            }
            else
            {
                // It's an operator, pop two operands
                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                // Combine and add parentheses
                string temp = "(" + op1 + c + op2 + ")";

                // Push the resulting string back
                st.push(temp);
            }
        }

        // The final element in the stack is the complete infix expression
        return st.top();
    }
};

int main()
{
    Solution obj;
    string exp = "*+AB-CD";

    cout << obj.prefixToInfix(exp) << "\n";
    // Expected output: ((A+B)*(C-D))

    return 0;
}