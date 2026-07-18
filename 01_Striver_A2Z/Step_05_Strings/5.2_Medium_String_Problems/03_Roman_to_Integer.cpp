#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

public:
    // 1. INTUITIVE: Left-to-Right pass using a Hash Map and peeking ahead
    // Time Complexity: O(N) | Space Complexity: O(1) (Map has fixed 7 elements)
    int romanToIntIntuitive(string s)
    {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            // If there is a next character and the current numeral is smaller than the next
            if (i + 1 < n && roman[s[i]] < roman[s[i + 1]])
            {
                total -= roman[s[i]];
            }
            else
            {
                total += roman[s[i]];
            }
        }
        return total;
    }

    // 2. OPTIMAL: Right-to-Left pass with Switch Helper
    // Time Complexity: O(N) | Space Complexity: O(1)
    int romanToIntOptimal(string s)
    {
        int n = s.length();
        int total = 0;
        int prevValue = 0; // Tracks the value of the character to our right

        // Scan backward from the last character down to 0
        for (int i = n - 1; i >= 0; i--)
        {
            int currentValue = getValue(s[i]);

            // If current symbol is smaller than the one to its right, subtract it
            if (currentValue < prevValue)
            {
                total -= currentValue;
            }
            else
            {
                // Otherwise, add it and update our peak value seen so far
                total += currentValue;
                prevValue = currentValue;
            }
        }
        return total;
    }
};

int main()
{
    Solution obj;
    string s1 = "III";     // 3
    string s2 = "LVIII";   // L = 50, V= 5, III = 3 -> 58
    string s3 = "MCMXCIV"; // M = 1000, CM = 900, XC = 90, IV = 4 -> 1994

    cout << "Intuitive Map (s=\"LVIII\")   : " << obj.romanToIntIntuitive(s2) << "\n";
    cout << "Optimal Scan  (s=\"MCMXCIV\") : " << obj.romanToIntOptimal(s3) << "\n";

    return 0;
}