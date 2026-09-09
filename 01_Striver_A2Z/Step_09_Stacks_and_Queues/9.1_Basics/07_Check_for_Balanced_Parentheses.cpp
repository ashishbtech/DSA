#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Repeatedly remove adjacent pairs
    // Time Complexity: O(N^2) | Space Complexity: O(N) for string copy
    bool isValidBrute(string s)
    {
        int len;
        do
        {
            len = s.length();
            size_t pos;
            if ((pos = s.find("()")) != string::npos)
                s.erase(pos, 2);
            else if ((pos = s.find("[]")) != string::npos)
                s.erase(pos, 2);
            else if ((pos = s.find("{}")) != string::npos)
                s.erase(pos, 2);
        } while (s.length() < len); // Keep looping if we removed something

        return s.length() == 0;
    }

    // OPTIMAL: Stack
    // Time Complexity: O(N) | Space Complexity: O(N)
    bool isValidOptimal(string s)
    {
        stack<char> st;

        for (char it : s)
        {
            // If it's an opening bracket, push to stack
            if (it == '(' || it == '{' || it == '[')
            {
                st.push(it);
            }
            else
            {
                // If it's a closing bracket, check for validity
                if (st.empty())
                    return false;

                char topChar = st.top();
                st.pop();

                // Check if the popped bracket matches the current closing bracket
                if ((it == ')' && topChar == '(') ||
                    (it == ']' && topChar == '[') ||
                    (it == '}' && topChar == '{'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets were successfully matched
        return st.empty();
    }
};

int main()
{
    Solution obj;
    string s1 = "()[{}()]";
    string s2 = "(]";

    cout << obj.isValidOptimal(s1) << "\n"; 
    cout << obj.isValidOptimal(s2) << "\n"; 

    return 0;
}