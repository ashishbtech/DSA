#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long countDistinctSubsequences(string s)
    {
        int n = s.length();
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        vector<int> last_occurrence(256, -1);

        for (int i = 1; i <= n; i++)
        {

            dp[i] = 2 * dp[i - 1];

            char currentChar = s[i - 1];
            if (last_occurrence[currentChar] != -1)
            {
                dp[i] = dp[i] - dp[last_occurrence[currentChar] - 1];
            }

            last_occurrence[currentChar] = i;
        }

        return dp[n];
    }

public:
    string betterString(string str1, string str2)
    {
        long long count1 = countDistinctSubsequences(str1);
        long long count2 = countDistinctSubsequences(str2);

        // If count1 >= count2, return str1 as per the problem description
        if (count1 >= count2)
        {
            return str1;
        }
        return str2;
    }
};

int main()
{
    Solution obj;
    string str1 = "gfg";
    string str2 = "ggg";

    string result = obj.betterString(str1, str2);
    cout << result << endl;

    return 0;
}