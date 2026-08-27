#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close)
    {

        if (curr.length() == 2 * n)
        {
            result.push_back(curr);
            return;
        }

        if (open < n)
        {
            curr.push_back('(');
            solve(n, curr, open + 1, close);
            curr.pop_back();
        }

        if (close < open)
        {
            curr.push_back(')');
            solve(n, curr, open, close + 1);
            curr.pop_back();
        }
    }
    // OPTIMAL: Smart Recursion (Backtracking)
    // Time Complexity: O(2^n)
    // Space Complexity: O(2^n)
    vector<string> generateParenthesis(int n)
    {
        string curr = "";
        solve(n, curr, 0, 0);
        return result;
    }
};

int main()
{
    Solution obj;
    int n = 3;

    vector<string> ans = obj.generateParenthesis(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}