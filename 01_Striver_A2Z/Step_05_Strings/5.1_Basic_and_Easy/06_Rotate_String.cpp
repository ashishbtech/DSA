#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Physically rotate the string character by character N times
    // Time Complexity: O(N^2) | Space Complexity: O(N) for string slicing
    bool rotateStringBrute(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s == goal)
            {
                return true;
            }
            // Perform one left shift: take char at index 0 and move to end
            s = s.substr(1) + s[0];
        }

        return false;
    }

    // 2. OPTIMAL: The Double Concatenation Substring Trick
    // Time Complexity: O(N) using KMP/standard string matching | Space Complexity: O(N) to store s + s
    bool rotateStringOptimal(string s, string goal)
    {
        // If lengths differ, s can never become goal
        if (s.length() != goal.length())
        {
            return false;
        }

        // Create the conveyor belt of all possible rotations
        string doubled = s + s;

        // If goal exists inside (s + s), it is a valid rotation
        return doubled.find(goal) != string::npos;
    }
};

int main()
{
    Solution obj;
    string s1 = "abcde", goal1 = "cdeab";
    string s2 = "abcde", goal2 = "abced";

    cout << "Brute Force (s=\"abcde\", goal=\"cdeab\") : "
         << (obj.rotateStringBrute(s1, goal1) ? "True (Valid Rotation)" : "False") << "\n";
    cout << "Optimal     (s=\"abcde\", goal=\"abced\") : "
         << (obj.rotateStringOptimal(s2, goal2) ? "True (Valid Rotation)" : "False") << "\n";

    return 0;
}