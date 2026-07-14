#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. VERTICAL SCANNING: Compare column by column
    // Time Complexity: O(N * M) | Space Complexity: O(1) auxiliary
    string longestCommonPrefixVertical(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].length(); i++)
        {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].length() || strs[j][i] != currentChar)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }

    // 2. OPTIMAL: Lexicographical Sort & Compare Extremes
    // Time Complexity: O(N log N * M) | Space Complexity: O(1) auxiliary
    string longestCommonPrefixSorting(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        // Sort the array lexicographically
        sort(strs.begin(), strs.end());

        // Grab the two most different strings (first and last)
        string first = strs[0];
        string last = strs.back();

        int i = 0;
        // Compare characters of first and last until mismatch or end of string
        while (i < first.length() && i < last.length() && first[i] == last[i])
        {
            i++;
        }

        return first.substr(0, i);
    }
};

int main()
{
    Solution obj;
    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Vertical Scan Approach : \"" << obj.longestCommonPrefixVertical(strs) << "\"\n";
    cout << "Sorting Approach       : \"" << obj.longestCommonPrefixSorting(strs) << "\"\n";

    return 0;
}