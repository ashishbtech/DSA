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
    // OPTIMAL: Stack-based string building (Left to Right)
    // Time Complexity: O(N) | Space Complexity: O(N)
    string postfixToInfix(string s)
    {
        stack<string> st;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (isOperand(c))
            {
                // Convert character to string and push
                st.push(string(1, c));
            }
            else
            {
                // Operator encountered, pop the last two operands
                // The first pop gives the right-hand operand
                string op2 = st.top();
                st.pop();

                // The second pop gives the left-hand operand
                string op1 = st.top();
                st.pop();

                // Combine them into a bracketed infix expression
                string temp = "(" + op1 + c + op2 + ")";

                // Push the resulting expression back to the stack
                st.push(temp);
            }
        }

        // The final element is the complete infix expression
        return st.top();
    }
};

int main()
{
    Solution obj;
    string exp = "AB+CD-*";

    cout << obj.postfixToInfix(exp) << "\n";
    // Expected output: ((A+B)*(C-D))

    return 0;
}