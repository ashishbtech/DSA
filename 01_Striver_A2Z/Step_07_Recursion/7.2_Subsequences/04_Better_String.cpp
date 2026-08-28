#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void generateSubsequences(int i, string s, string current, unordered_set<string> &unique_subs)
    {
        // Base Case: Reached the end of the string
        if (i == s.length())
        {
            unique_subs.insert(current);
            return;
        }

        // Choice 1: Pick the current character
        generateSubsequences(i + 1, s, current + s[i], unique_subs);

        // Choice 2: Don't pick the current character
        generateSubsequences(i + 1, s, current, unique_subs);
    }

public:
    //  TLE will hit, optimization will be done with dp
     // Time Complexity: O(2^n) | Space Complexity: O(N) auxiliary stack space
    string betterString(string s1, string s2)
    {
        unordered_set<string> set1, set2;

        // Start recursion from index 0 with an empty current string
        generateSubsequences(0, s1, "", set1);
        generateSubsequences(0, s2, "", set2);

        // Compare the sizes of the sets
        if (set1.size() >= set2.size())
        {
            return s1;
        }
        else
        {
            return s2;
        }
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