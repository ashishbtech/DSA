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
    string postfixToPrefix(string s)
    {
        stack<string> st;

        // Traverse from left to right for postfix
        for (int i = 0; i < s.length(); i++)
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
                // Top element is the right operand in postfix evaluation
                string op2 = st.top();
                st.pop();

                string op1 = st.top();
                st.pop();

                // Combine in prefix order: Operator Left Right
                string temp = c + op1 + op2;

                // Push back to stack
                st.push(temp);
            }
        }

        // The final element is the complete prefix expression
        return st.top();
    }
};

int main()
{
    Solution obj;
    string exp = "AB+CD-*";

    cout << obj.postfixToPrefix(exp) << "\n";
    // Expected output: *+AB-CD

    return 0;
}