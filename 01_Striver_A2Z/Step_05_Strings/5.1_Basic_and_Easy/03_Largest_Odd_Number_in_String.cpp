#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Check all possible substrings
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    string largestOddNumberBrute(string num)
    {
        string maxOdd = "";
        int n = num.length();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // A substring is odd if its ending character is odd
                if ((num[j] - '0') % 2 != 0)
                {
                    string sub = num.substr(i, j - i + 1);
                    // Compare numerically: longer strings are bigger; if lengths equal, compare lexicographically
                    if (sub.length() > maxOdd.length() ||
                        (sub.length() == maxOdd.length() && sub > maxOdd))
                    {
                        maxOdd = sub;
                    }
                }
            }
        }
        return maxOdd;
    }

    // 2. OPTIMAL: Single Right-to-Left Greedy Scan
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    string largestOddNumberOptimal(string num)
    {
        int n = num.length();

        // Scan backward starting from the very last digit
        for (int i = n - 1; i >= 0; i--)
        {
            // Convert ASCII char to integer and check parity
            if ((num[i] - '0') % 2 != 0)
            {
                // The moment we hit an odd digit, grab everything from 0 to i
                return num.substr(0, i + 1);
            }
        }

        // No odd digits found in the entire string
        return "";
    }
};

int main()
{
    Solution obj;
    string num = "3542786";

    cout << "Brute Force   : \"" << obj.largestOddNumberBrute(num) << "\"\n";
    cout << "Optimal Scan  : \"" << obj.largestOddNumberOptimal(num) << "\"\n";

    return 0;
}