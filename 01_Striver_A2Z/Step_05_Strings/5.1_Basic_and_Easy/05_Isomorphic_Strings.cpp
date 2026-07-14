#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Check every pair of indices (i, j)
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    bool isIsomorphicBrute(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // If s[i] and s[j] match, t[i] and t[j] must also match.
                // If s[i] and s[j] differ, t[i] and t[j] must also differ.
                if ((s[i] == s[j] && t[i] != t[j]) || (s[i] != s[j] && t[i] == t[j]))
                {
                    return false;
                }
            }
        }
        return true;
    }

    // 2. BETTER: Two-Way ASCII Lookup Arrays
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool isIsomorphicBetter(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        vector<int> mapS2T(256, -1);
        vector<int> mapT2S(256, -1);

        for (int i = 0; i < s.length(); i++)
        {
            char charS = s[i];
            char charT = t[i];

            if (mapS2T[charS] != -1 && mapS2T[charS] != charT)
                return false;
            if (mapT2S[charT] != -1 && mapT2S[charT] != charS)
                return false;

            mapS2T[charS] = charT;
            mapT2S[charT] = charS;
        }
        return true;
    }

    // 3. OPTIMAL: Structural "Last Seen Index" Matching
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool isIsomorphicOptimal(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int lastSeenS[256] = {0};
        int lastSeenT[256] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            if (lastSeenS[s[i]] != lastSeenT[t[i]])
            {
                return false;
            }
            lastSeenS[s[i]] = i + 1;
            lastSeenT[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    string s1 = "egg", t1 = "add";
    string s2 = "foo", t2 = "bar";
    string s3 = "paper", t3 = "title";

    cout << "Brute Force (s=\"foo\", t=\"bar\") : "
         << (obj.isIsomorphicBrute(s2, t2) ? "True" : "False") << "\n";
    cout << "Better      (s=\"egg\", t=\"add\") : "
         << (obj.isIsomorphicBetter(s1, t1) ? "True" : "False") << "\n";
    cout << "Optimal     (s=\"paper\", t=\"title\") : "
         << (obj.isIsomorphicOptimal(s3, t3) ? "True" : "False") << "\n";

    return 0;
}