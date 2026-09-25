#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Nested loops with early break math
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int numberOfSubstringsBrute(string s)
    {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> hash(3, 0); // To track 'a', 'b', 'c'
            for (int j = i; j < n; j++)
            {
                hash[s[j] - 'a'] = 1;

                // If we have seen all three characters
                if (hash[0] == 1 && hash[1] == 1 && hash[2] == 1)
                {
                    // All substrings ending from j to n-1 are valid
                    count += (n - j);
                    break;
                }
            }
        }
        return count;
    }

    // OPTIMAL: Track last seen indices
    // Time Complexity: O(N) | Space Complexity: O(1)
    int numberOfSubstringsOptimal(string s)
    {
        int n = s.length();
        int count = 0;
        vector<int> lastSeen(3, -1);

        for (int i = 0; i < n; i++)
        {
            // Update the last seen index of the current character
            lastSeen[s[i] - 'a'] = i;

            // If all three characters have been encountered at least once
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {

                int min_idx = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                count += (min_idx + 1);
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    string s1 = "abcabc";
    cout << "String: " << s1 << "\n";
    cout << "Brute Force: " << obj.numberOfSubstringsBrute(s1) << "\n";
    cout << "Optimal: " << obj.numberOfSubstringsOptimal(s1) << "\n";

    cout << "---\n";

    string s2 = "aaacb";
    cout << "String: " << s2 << "\n";
    cout << "Optimal: " << obj.numberOfSubstringsOptimal(s2) << "\n";

    cout << "---\n";

    string s3 = "abc";
    cout << "String: " << s3 << "\n";
    cout << "Optimal: " << obj.numberOfSubstringsOptimal(s3) << "\n";

    return 0;
}