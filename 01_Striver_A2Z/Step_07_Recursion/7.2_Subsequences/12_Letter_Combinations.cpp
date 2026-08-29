#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int index, string &digits, string &current, vector<string> &ans, const vector<string> &mapping)
    {
        // Base case
        if (index == digits.length())
        {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        string letters = mapping[digit];

        for (int i = 0; i < letters.length(); i++)
        {
            // Pick the letter
            current.push_back(letters[i]);

            // Recurse to the next digit in the input string
            solve(index + 1, digits, current, ans, mapping);

            // Backtrack: Remove the letter to try the next one
            current.pop_back();
        }
    }

public:
    // OPTIMAL: Backtracking with mapping
    // Time Complexity: O(4^N * N) where N is length of digits | Space: O(N) Call Stack
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if (digits.empty())
            return ans;

        string current = "";

        // Map indices 0-9 to their corresponding phone keypad letters
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(0, digits, current, ans, mapping);

        return ans;
    }
};

int main()
{
    Solution obj;
    string digits = "23";

    vector<string> ans = obj.letterCombinations(digits);

    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\"" << ans[i] << "\" ";
    }
    cout << "]\n";

    return 0;
}