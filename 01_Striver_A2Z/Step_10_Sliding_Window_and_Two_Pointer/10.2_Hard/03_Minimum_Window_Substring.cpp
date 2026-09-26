#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Generate all substrings and validate character frequencies
    // Time Complexity: O(N^2) | Space Complexity: O(256) ~ O(1)
    string minWindowBrute(string s, string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
            return "";

        int minLen = INT_MAX;
        int startIndex = -1;
        int n = s.length();

        vector<int> targetHash(256, 0);
        for (char c : t)
        {
            targetHash[c]++;
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> currentHash(256, 0);
            int matched = 0;

            for (int j = i; j < n; j++)
            {
                currentHash[s[j]]++;

                // If this character is useful for matching t
                if (currentHash[s[j]] <= targetHash[s[j]])
                {
                    matched++;
                }

                // If we found a valid window
                if (matched == t.length())
                {
                    if (j - i + 1 < minLen)
                    {
                        minLen = j - i + 1;
                        startIndex = i;
                    }
                    break; // No need to expand further, we want the minimum window starting at i
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }

    // OPTIMAL: Sliding Window with required counter
    // Time Complexity: O(N) | Space Complexity: O(256) ~ O(1)
    string minWindowOptimal(string s, string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
            return "";

        vector<int> hash(256, 0);
        for (char c : t)
        {
            hash[c]++; // Positive count means the character is required
        }

        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        int required = t.length();

        while (right < s.length())
        {
            // If the character is required, decrease the required count
            if (hash[s[right]] > 0)
            {
                required--;
            }
            // Always decrease the hash count (unneeded characters become negative)
            hash[s[right]]--;

            // When all required characters are in the current window
            while (required == 0)
            {
                // Update the minimum window
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Try to shrink the window from the left
                hash[s[left]]++;

                // If after removing the left character, it becomes > 0, it means we lost a required character
                if (hash[s[left]] > 0)
                {
                    required++;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

int main()
{
    Solution obj;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "String: " << s1 << " | Target: " << t1 << "\n";
    cout << "Brute Force: " << obj.minWindowBrute(s1, t1) << "\n";
    cout << "Optimal: " << obj.minWindowOptimal(s1, t1) << "\n";

    cout << "---\n";

    string s2 = "a";
    string t2 = "a";
    cout << "String: " << s2 << " | Target: " << t2 << "\n";
    cout << "Optimal: " << obj.minWindowOptimal(s2, t2) << "\n";

    cout << "---\n";

    string s3 = "a";
    string t3 = "aa";
    cout << "String: " << s3 << " | Target: " << t3 << "\n";
    cout << "Optimal: " << obj.minWindowOptimal(s3, t3) << "\n";

    return 0;
}