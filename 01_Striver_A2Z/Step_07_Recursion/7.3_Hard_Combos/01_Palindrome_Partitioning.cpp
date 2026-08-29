#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(int index, string &s, vector<string> &current, vector<vector<string>> &ans)
    {
        // Base case
        if (index == s.length())
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {

            // Check if the left side of the divider is a valid palindrome
            if (isPalindrome(s, index, i))
            {

                // 1. Pick this palindrome substring
                current.push_back(s.substr(index, i - index + 1));

                // 2. Recurse to partition the REST of the string
                solve(i + 1, s, current, ans);

                // 3. Backtrack to try placing the divider further down
                current.pop_back();
            }
        }
    }

public:
    // OPTIMAL: Backtracking with Palindrome Checking
    // Time Complexity: O(2^N * N) | Space Complexity: O(N) for Call Stack
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> current;
        solve(0, s, current, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "aab";

    vector<vector<string>> ans = obj.partition(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << "\"" << ans[i][j] << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}