#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // swap characters in-place using two pointers
    void reverseSubstring(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

public:
    // 1. BRUTE FORCE: Using StringStream and extra memory allocation
    // Time Complexity: O(N) | Space Complexity: O(N)
    string reverseWordsBrute(string s)
    {
        stringstream ss(s);
        string word;
        string result = "";

        while (ss >> word)
        {

            reverse(word.begin(), word.end());
            result += word + " ";
        }

        if (!result.empty())
        {
            result.pop_back();
        }

        return result;
    }

    // 2. OPTIMAL: In-Place Two-Pointer Scan
    // Time Complexity: O(N) | Space Complexity: O(1)
    string reverseWordsOptimal(string s)
    {
        int n = s.length();
        int start = 0;

        for (int end = 0; end <= n; end++)
        {

            if (end == n || s[end] == ' ')
            {

                reverseSubstring(s, start, end - 1);

                start = end + 1;
            }
        }

        return s;
    }
};

int main()
{
    Solution obj;
    string s1 = "Let's take LeetCode contest";
    string s2 = "Mr Ding";

    cout << "Brute Force (s1) : \"" << obj.reverseWordsBrute(s1) << "\"\n";
    cout << "Optimal     (s2) : \"" << obj.reverseWordsOptimal(s2) << "\"\n";

    return 0;
}