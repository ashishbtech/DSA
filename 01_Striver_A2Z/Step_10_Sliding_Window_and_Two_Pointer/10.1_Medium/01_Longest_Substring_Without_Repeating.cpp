#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Generate all substrings and check for duplicates
    // Time Complexity: O(N^2) | Space Complexity: O(256) ~ O(1)
    int lengthOfLongestSubstringBrute(string s)
    {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            vector<bool> hash(256, false);
            for (int j = i; j < n; j++)
            {

                if (hash[s[j]] == true)
                {
                    break;
                }

                hash[s[j]] = true;
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }

    // OPTIMAL: Sliding Window with Two Pointers and Index Hashing
    // Time Complexity: O(N) | Space Complexity: O(256) ~ O(1)
    int lengthOfLongestSubstringOptimal(string s)
    {
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        int right = 0;

        vector<int> hash(256, -1);

        while (right < n)
        {

            if (hash[s[right]] != -1 && hash[s[right]] >= left)
            {

                left = hash[s[right]] + 1;
            }

            int len = right - left + 1;
            maxLen = max(maxLen, len);

            hash[s[right]] = right;

            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    string s1 = "abcabcbb";
    cout << "String: " << s1 << "\n";
    cout << "Brute Force: " << obj.lengthOfLongestSubstringBrute(s1) << "\n";
    cout << "Optimal: " << obj.lengthOfLongestSubstringOptimal(s1) << "\n";

    cout << "---\n";

    string s2 = "bbbbb";
    cout << "String: " << s2 << "\n";
    cout << "Optimal: " << obj.lengthOfLongestSubstringOptimal(s2) << "\n";

    cout << "---\n";

    string s3 = "pwwkew";
    cout << "String: " << s3 << "\n";
    cout << "Optimal: " << obj.lengthOfLongestSubstringOptimal(s3) << "\n";

    return 0;
}