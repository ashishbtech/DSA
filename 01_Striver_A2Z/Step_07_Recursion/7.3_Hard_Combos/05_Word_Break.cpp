#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int index, string &s, unordered_set<string> &wordSet)
    {
        // Base case
        if (index == s.length())
        {
            return true;
        }

        string currentSlice = "";

        for (int i = index; i < s.length(); i++)
        {
            currentSlice += s[i];

            if (wordSet.find(currentSlice) != wordSet.end())
            {

                if (solve(i + 1, s, wordSet))
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    // PURE RECURSION: For-loop partitioning with boolean short-circuiting
    // Time Complexity: O(2^N) worst case (will TLE without DP)
    // Space Complexity: O(N) for Call Stack + O(W) for HashSet
    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        return solve(0, s, wordSet);
    }
};

int main()
{
    Solution obj;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (obj.wordBreak(s, wordDict))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}