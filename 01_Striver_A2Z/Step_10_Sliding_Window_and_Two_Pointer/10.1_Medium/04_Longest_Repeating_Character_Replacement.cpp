#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Generate all substrings and check replacement count
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int characterReplacementBrute(string s, int k)
    {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> hash(26, 0);
            int maxFreq = 0;

            for (int j = i; j < n; j++)
            {
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);

                int replacements = (j - i + 1) - maxFreq;

                if (replacements <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                {

                    break;
                }
            }
        }
        return maxLen;
    }

    // OPTIMAL: Sliding Window with historical max frequency
    // Time Complexity: O(N) | Space Complexity: O(1)
    int characterReplacementOptimal(string s, int k)
    {
        int n = s.length();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> hash(26, 0);

        while (right < n)
        {
            // Include the current character in the window
            hash[s[right] - 'A']++;
            // Update the historical maximum frequency
            maxFreq = max(maxFreq, hash[s[right] - 'A']);

            // If the number of characters we need to replace exceeds k, shrink window
            while ((right - left + 1) - maxFreq > k)
            {
                hash[s[left] - 'A']--;
                left++;
                // Note: We intentionally DO NOT update maxFreq here to keep it O(1) time.
                // We only care if maxFreq grows large enough to yield a bigger window later.
            }

            // If we reach here, the window is valid (or conceptually safely bounded)
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    string s1 = "ABAB";
    int k1 = 2;
    cout << "String: " << s1 << " | k: " << k1 << "\n";
    cout << "Brute Force: " << obj.characterReplacementBrute(s1, k1) << "\n";
    cout << "Optimal: " << obj.characterReplacementOptimal(s1, k1) << "\n";

    cout << "---\n";

    string s2 = "AABABBA";
    int k2 = 1;
    cout << "String: " << s2 << " | k: " << k2 << "\n";
    cout << "Optimal: " << obj.characterReplacementOptimal(s2, k2) << "\n";

    cout << "---\n";

    return 0;
}