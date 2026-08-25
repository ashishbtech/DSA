#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursive helper to process digits and compute the final integer
    long long solve(string &s, int index, long long result, int sign)
    {

        // 5. Base Case
        if (index == s.length() || !isdigit(s[index]))
        {
            return result * sign;
        }

        // 1. Take current character
        char ch = s[index];
        // 2. Convert the character into a digit
        int digit = ch - '0';
        // Overflow condition
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        // 3. UPdate the result
        result = result * 10 + digit;
        // 4 . call the recursion
        return solve(s, index + 1, result, sign);
    }

public:
    int myAtoi(string s)
    {
        int index = 0;
        // Condition 1-> Ignoring the leading spaces
        while (index < s.length() && s[index] == ' ')
        {
            index++;
        }

        // String containing only spaces
        if (index == s.length())
        {
            return 0;
        }
        // Condition 2-> Check the sign

        int sign = 1;
        if (s[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (s[index] == '+')
        {
            sign = 1;
            index++;
        }
        // Condition 3-> No digit after sign
        if (index == s.length() || !isdigit(s[index]))
        {
            return 0;
        }

        // Start recursion
        return solve(s, index, 0, sign);
    }
};

int main()
{
    Solution obj;

    string test1 = "   -42";
    string test2 = "4193 with words";
    string test3 = "words and 987";
    string test4 = "-91283472332"; // Underflow test

    cout << "Input: \"" << test1 << "\" -> Output: " << obj.myAtoi(test1) << "\n";
    cout << "Input: \"" << test2 << "\" -> Output: " << obj.myAtoi(test2) << "\n";
    cout << "Input: \"" << test3 << "\" -> Output: " << obj.myAtoi(test3) << "\n";
    cout << "Input: \"" << test4 << "\" -> Output: " << obj.myAtoi(test4) << "\n";

    return 0;
}