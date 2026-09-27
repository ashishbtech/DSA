#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Check all substrings
    // Time Complexity: O(N^3) | Space Complexity: O(1)
    string minWindowBrute(string s, string t)
    {
        int n = s.length(), m = t.length();
        string minStr = "";
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                int tIdx = 0;
                for (int k = i; k <= j && tIdx < m; k++)
                {
                    if (s[k] == t[tIdx])
                    {
                        tIdx++;
                    }
                }

                if (tIdx == m)
                {
                    if (j - i + 1 < minLen)
                    {
                        minLen = j - i + 1;
                        minStr = s.substr(i, minLen);
                    }

                    break;
                }
            }
        }
        return minStr;
    }

    // OPTIMAL: Expand forward to find end, shrink backward to find start
    // Time Complexity: O(N * M) worst case | Space Complexity: O(1)
    string minWindowOptimal(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        int minLen = INT_MAX;
        int startIndex = -1;

        int i = 0, j = 0;

        while (i < n)
        {
            // Expand forward to match T
            if (s[i] == t[j])
            {
                j++;
            }

            // If all characters of T are matched
            if (j == m)
            {
                int end = i;
                j--; // Point to the last character of T

                // Shrink backward to find the exact starting index
                while (j >= 0)
                {
                    if (s[i] == t[j])
                    {
                        j--;
                    }
                    i--;
                }

                // i went one step too far to the left during the loop
                i++;

                // Update minimum window
                if (end - i + 1 < minLen)
                {
                    minLen = end - i + 1;
                    startIndex = i;
                }

                // Start the next search from the character right after our valid start
                j = 0;
            }
            i++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};

int main()
{
    Solution obj;

    string s1 = "abcdebdde";
    string t1 = "bde";
    cout << "String S: " << s1 << " | String T: " << t1 << "\n";
    cout << "Brute Force: " << obj.minWindowBrute(s1, t1) << "\n";
    cout << "Optimal: " << obj.minWindowOptimal(s1, t1) << "\n";

    cout << "---\n";

    string s2 = "jmeqksfrsdcmsiwvaovztaqenprpvnbwthg";
    string t2 = "u";
    cout << "String S: " << s2 << " | String T: " << t2 << "\n";
    cout << "Optimal: " << obj.minWindowOptimal(s2, t2) << "\n";

    return 0;
}