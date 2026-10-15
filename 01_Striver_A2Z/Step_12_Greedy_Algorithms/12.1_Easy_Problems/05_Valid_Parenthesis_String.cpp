#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Recursion (TLE)
    // Time Complexity: O(3^N) | Space Complexity: O(N)
    bool checkValidStringBrute(string s)
    {
        return solve(s, 0, 0);
    }

    bool solve(string &s, int index, int count)
    {
        // If we have more closing than opening at any point, invalid
        if (count < 0)
            return false;

        // Base case: end of string, valid if exactly 0 open remaining
        if (index == s.length())
            return count == 0;

        if (s[index] == '(')
        {
            return solve(s, index + 1, count + 1);
        }
        else if (s[index] == ')')
        {
            return solve(s, index + 1, count - 1);
        }
        else
        {
            // s[index] == '*' -> Try all 3 possibilities
            // 1. Try as '('
            // 2. Try as empty string ''
            // 3. Try as ')'
            return solve(s, index + 1, count + 1) ||
                   solve(s, index + 1, count) ||
                   solve(s, index + 1, count - 1);
        }
    }

    // OPTIMAL: Greedy Range Tracking
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool checkValidStringOptimal(string s)
    {
        int minOpen = 0; // Minimum possible open parentheses
        int maxOpen = 0; // Maximum possible open parentheses

        for (char c : s)
        {
            if (c == '(')
            {
                minOpen++;
                maxOpen++;
            }
            else if (c == ')')
            {
                minOpen--;
                maxOpen--;
            }
            else
            {              // c == '*'
                minOpen--; // Assume it acts as ')'
                maxOpen++; // Assume it acts as '('
            }

            if (maxOpen < 0)
            {
                return false;
            }

            if (minOpen < 0)
            {
                minOpen = 0;
            }
        }

        // It's valid if we can reach exactly 0 open parentheses
        return minOpen == 0;
    }
};

void printResult(bool result)
{
    cout << (result ? "True (Valid)" : "False (Invalid)") << "\n";
}

int main()
{
    Solution obj;

    string s1 = "()";
    cout << "String: \"" << s1 << "\"\nResult: ";
    printResult(obj.checkValidStringOptimal(s1));

    cout << "---\n";

    string s2 = "(*)";
    cout << "String: \"" << s2 << "\"\nResult: ";
    printResult(obj.checkValidStringOptimal(s2));
    cout << "---\n";

    string s3 = "(*))";
    cout << "String: \"" << s3 << "\"\nResult: ";
    printResult(obj.checkValidStringOptimal(s3));
    cout << "---\n";

    string s4 = "*(**)";
    cout << "String: \"" << s4 << "\"\nResult: ";
    printResult(obj.checkValidStringOptimal(s4));

    return 0;
}