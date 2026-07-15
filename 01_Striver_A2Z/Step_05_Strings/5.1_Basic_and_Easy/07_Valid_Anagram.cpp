#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Sort both strings and compare
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    bool isAnagramBrute(string s, string t)
    {
      
        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    // 2. OPTIMAL: Single-Pass Frequency Array
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool isAnagramOptimal(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        // Frequency table for lowercase English alphabet
        int freq[26] = {0};

        // Single pass: Add for string s, subtract for string t
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // Verify that all buckets returned to zero
        for (int count : freq)
        {
            if (count != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    cout << "Brute Force (s=\"anagram\", t=\"nagaram\") : "
         << (obj.isAnagramBrute(s1, t1) ? "True (Valid Anagram)" : "False") << "\n";
    cout << "Optimal     (s=\"rat\", t=\"car\")         : "
         << (obj.isAnagramOptimal(s2, t2) ? "True (Valid Anagram)" : "False") << "\n";

    return 0;
}