#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Using StringStream and Stack
    // Time Complexity: O(N) | Space Complexity: O(N)
    string reverseWordsStack(string s)
    {
        stringstream ss(s);
        string word;
        stack<string> st;

        // Extract words automatically ignoring multiple spaces
        while (ss >> word)
        {
            st.push(word);
        }

        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
            if (!st.empty())
            {
                result = result + " "; // Add space between words, but not after the last word
            }
        }
        return result;
    }

    // 2. OPTIMAL: Two Pointers scanning from Right to Left
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    string reverseWordsOptimal(string s)
    {
        int n = s.length();
        string result = "";
        int i = n - 1;

        while (i >= 0)
        {
            // 1. Skip trailing/intermediate spaces
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }

            // If we ran out of characters, break out of the loop
            if (i < 0)
                break;

            // 2. Mark the end of the current word
            int j = i;

            // 3. Move 'i' to the beginning of the current word
            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }

            // 4. Append a space if the result isn't empty (means we already added a word prior)
            if (!result.empty())
            {
                result += " ";
            }

            // 5. Append the word from index [i + 1] to [j]
            result.append(s, i + 1, j - i);
        }

        return result;
    }
};

int main()
{
    Solution obj;
    string s = "  hello world  ";

    cout << "Stack Approach   : \"" << obj.reverseWordsStack(s) << "\"\n";
    cout << "Optimal Approach : \"" << obj.reverseWordsOptimal(s) << "\"\n";

    return 0;
}