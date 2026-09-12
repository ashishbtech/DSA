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
    string prefixToPostfix(string s)
    {
        stack<string> st;

        // Traverse from right to left
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (isOperand(c))
            {
                // Convert char to string and push
                st.push(string(1, c));
            }
            else
            {
                // It's an operator, pop two operands
                // Since we read right-to-left, the top is the left operand
                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                // Combine in postfix order: Left Right Operator
                string temp = op1 + op2 + c;

                // Push back to stack
                st.push(temp);
            }
        }

        // The final element is the complete postfix expression
        return st.top();
    }
};

int main()
{
    Solution obj;
    string exp = "*+AB-CD";

    cout << obj.prefixToPostfix(exp) << "\n";
    // Expected output: AB+CD-*

    return 0;
}