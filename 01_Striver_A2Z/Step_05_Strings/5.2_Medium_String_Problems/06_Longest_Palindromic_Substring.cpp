#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int expandAroundCenter(const string &s, int left, int right)
    {

        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right - left - 1;
    }

    // Helper for Brute Force
    bool isPalindrome(const string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    // 1. BRUTE FORCE: Generate all substrings and check if they are palindromes
    // Time Complexity: O(N^3) | Space Complexity: O(1)
    string longestPalindromeBrute(string s)
    {
        if (s.empty())
            return "";

        int maxLen = 0;
        int startIdx = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    int currentLen = j - i + 1;
                    if (currentLen > maxLen)
                    {
                        maxLen = currentLen;
                        startIdx = i;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);
    }

    // 2. OPTIMAL: Expand Around Center (Handles both odd and even centers)
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    string longestPalindromeOptimal(string s)
    {
        if (s.length() <= 1)
            return s;

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // Case 1: Odd length palindrome (center is at character i)
            int len1 = expandAroundCenter(s, i, i);

            // Case 2: Even length palindrome (center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);

            // Take the longest palindrome found from this center
            int currentMax = max(len1, len2);

            // If we found a new record, calculate its starting index
            if (currentMax > maxLen)
            {
                maxLen = currentMax;
                // Math to derive start index from center i and total length
                start = i - (currentMax - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main()
{
    Solution obj;
    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "racecar";

    cout << "Brute Force (s=\"babad\")   : \"" << obj.longestPalindromeBrute(s1) << "\"\n";
    cout << "Optimal     (s=\"cbbd\")    : \"" << obj.longestPalindromeOptimal(s2) << "\"\n";
    cout << "Optimal     (s=\"racecar\") : \"" << obj.longestPalindromeOptimal(s3) << "\"\n";

    return 0;
}