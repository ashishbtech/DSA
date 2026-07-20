#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countAtMostKDistinct(string s, int k)
    {
        if (k < 0)
            return 0;

        int n = s.length();
        int freq[26] = {0};
        int left = 0, right = 0;
        int distinctCount = 0;
        int totalSubstrings = 0;

        while (right < n)
        {
            // Expand window to the right
            if (freq[s[right] - 'a'] == 0)
            {
                distinctCount++;
            }
            freq[s[right] - 'a']++;

            // shrink window from the left if distinct characters exceed k
            while (distinctCount > k)
            {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                {
                    distinctCount--;
                }
                left++;
            }

            // All suffixes ending at 'right' and starting anywhere from 'left' to 'right' are valid
            totalSubstrings += (right - left + 1);
            right++;
        }

        return totalSubstrings;
    }

public:
    // 1. BRUTE FORCE: Nested loops checking every substring
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    int countExactKBrute(string s, int k)
    {
        int n = s.length();
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};
            int distinctCount = 0;

            for (int j = i; j < n; j++)
            {
                if (freq[s[j] - 'a'] == 0)
                {
                    distinctCount++;
                }
                freq[s[j] - 'a']++;

                if (distinctCount == k)
                {
                    total++;
                }
                else if (distinctCount > k)
                {
                    break;
                }
            }
        }
        return total;
    }

    // 2. OPTIMAL: Algebraic difference of two sliding windows
    // Time Complexity: O(N) (Two linear scans) | Space Complexity: O(1)
    int countExactKOptimal(string s, int k)
    {
        // Exactly(K) = AtMost(K) - AtMost(K - 1)
        return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
    }
};

int main()
{
    Solution obj;
    string s1 = "pqpqs";
    int k1 = 2; // Expected output: 7 ("pq", "pqp", "pqpq", "qp", "qpq", "pq", "qs")

    string s2 = "aabaab";
    int k2 = 3; // Expected output: 0 (String only has 'a' and 'b', impossible to get 3 distinct)

    cout << "Brute Force (s=\"pqpqs\", k=2)  : " << obj.countExactKBrute(s1, k1) << "\n";
    cout << "Optimal     (s=\"pqpqs\", k=2)  : " << obj.countExactKOptimal(s1, k1) << "\n";
    cout << "Optimal     (s=\"aabaab\", k=3) : " << obj.countExactKOptimal(s2, k2) << "\n";

    return 0;
}