#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getBeauty(int freq[])
    {
        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                maxFreq = max(maxFreq, freq[i]);
                minFreq = min(minFreq, freq[i]);
            }
        }

        return maxFreq - minFreq;
    }

public:
    // 1. BRUTE FORCE: Recomputing frequency arrays from scratch for every substring
    // Time Complexity: O(N^3) | Space Complexity: O(26)
    int beautySumBrute(string s)
    {
        int totalBeauty = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int freq[26] = {0};
                for (int k = i; k <= j; k++)
                {
                    freq[s[k] - 'a']++;
                }
                totalBeauty += getBeauty(freq);
            }
        }

        return totalBeauty;
    }

    // 2. OPTIMAL: Rolling Frequency Array updated dynamically as 'j' expands
    // Time Complexity: O(N^2 * 26) ~ O(N^2) | Space Complexity: O(1)
    int beautySumOptimal(string s)
    {
        int totalBeauty = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};

            for (int j = i; j < n; j++)
            {

                freq[s[j] - 'a']++;

                totalBeauty += getBeauty(freq);
            }
        }

        return totalBeauty;
    }
};

int main()
{
    Solution obj;
    string s1 = "aabcb";

    string s2 = "aabcbaa";

    cout << "Brute Force (s=\"aabcb\")   : Total Beauty = " << obj.beautySumBrute(s1) << "\n";
    cout << "Optimal     (s=\"aabcbaa\") : Total Beauty = " << obj.beautySumOptimal(s2) << "\n";

    return 0;
}