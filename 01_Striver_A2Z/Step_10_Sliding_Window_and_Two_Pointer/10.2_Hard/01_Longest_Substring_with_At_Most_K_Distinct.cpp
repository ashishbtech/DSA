#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Generate all substrings and use a set
    // Time Complexity: O(N^2) | Space Complexity: O(K)
    int lengthOfLongestSubstringKDistinctBrute(string s, int k)
    {
        if (k == 0)
            return 0;

        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<char> st;
            for (int j = i; j < n; j++)
            {
                st.insert(s[j]);

                // If distinct characters exceed k, stop expanding
                if (st.size() > k)
                {
                    break;
                }

                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // OPTIMAL: Sliding Window with a frequency map
    // Time Complexity: O(N) | Space Complexity: O(K)
    int lengthOfLongestSubstringKDistinctOptimal(string s, int k)
    {
        if (k == 0)
            return 0;

        int n = s.length();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<char, int> mpp;

        while (right < n)
        {
            // Add current character to the map
            mpp[s[right]]++;

            // If window is invalid, shrink from the left
            while (mpp.size() > k)
            {
                mpp[s[left]]--;

                // If frequency hits 0, erase it to reduce distinct count
                if (mpp[s[left]] == 0)
                {
                    mpp.erase(s[left]);
                }
                left++;
            }

            // Window is valid, calculate max length
            maxLen = max(maxLen, right - left + 1);

            // Expand to the next character
            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    string s1 = "eceba";
    int k1 = 2;
    cout << "String: " << s1 << " | k: " << k1 << "\n";
    cout << "Brute Force: " << obj.lengthOfLongestSubstringKDistinctBrute(s1, k1) << "\n";
    cout << "Optimal: " << obj.lengthOfLongestSubstringKDistinctOptimal(s1, k1) << "\n";

    cout << "---\n";

    string s2 = "aa";
    int k2 = 1;
    cout << "String: " << s2 << " | k: " << k2 << "\n";
    cout << "Optimal: " << obj.lengthOfLongestSubstringKDistinctOptimal(s2, k2) << "\n";

    cout << "---\n";

    string s3 = "aabacbebebe";
    int k3 = 3;
    cout << "String: " << s3 << " | k: " << k3 << "\n";
    cout << "Optimal: " << obj.lengthOfLongestSubstringKDistinctOptimal(s3, k3) << "\n";

    return 0;
}