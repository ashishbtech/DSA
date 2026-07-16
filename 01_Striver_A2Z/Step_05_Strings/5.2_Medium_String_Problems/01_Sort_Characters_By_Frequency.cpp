#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Count frequencies and sort the string using a custom comparator
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    string frequencySortBrute(string s)
    {
        int freq[256] = {0};
        for (char c : s)
        {
            freq[c]++;
        }

        // Sort characters based on their frequency
        sort(s.begin(), s.end(), [&](char a, char b)
             {
            if (freq[a] == freq[b]) {
                return a < b; 
            }
            return freq[a] > freq[b]; });

        return s;
    }

    // 2. OPTIMAL: Bucket Sort in strictly linear time
    // Time Complexity: O(N) | Space Complexity: O(N)
    string frequencySortOptimal(string s)
    {
        int n = s.length();
        int freq[256] = {0};

        // Step 1: Count character frequencies
        for (char c : s)
        {
            freq[c]++;
        }

        // Step 2: Create buckets where index = frequency
        vector<string> buckets(n + 1, "");
        for (int i = 0; i < 256; i++)
        {
            if (freq[i] > 0)
            {
                buckets[freq[i]] += (char)i;
            }
        }

        // Step 3: Reconstruct the string by reading buckets from highest frequency to lowest
        string result = "";
        for (int i = n; i >= 1; i--)
        {
            for (char c : buckets[i])
            {
                result.append(i, c);
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    string s1 = "tree";
    string s2 = "cccaaa";
    string s3 = "Aabb";

    cout << "Brute Force (s=\"tree\")   : \"" << obj.frequencySortBrute(s1) << "\"\n";
    cout << "Optimal     (s=\"cccaaa\") : \"" << obj.frequencySortOptimal(s2) << "\"\n";
    cout << "Optimal     (s=\"Aabb\")   : \"" << obj.frequencySortOptimal(s3) << "\"\n";

    return 0;
}