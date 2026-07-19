#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. STANDARD PRACTICAL: Using 'long' to easily catch overflow
    // Time Complexity: O(N) | Space Complexity: O(1)
    int myAtoiPractical(string s)
    {
        int i = 0, n = s.length();
        int sign = 1;
        long result = 0; // 64-bit integer absorbs overflow safely

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process numerical digits
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // Clamp immediately if we exceed 32-bit boundaries
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }

    // 2. OPTIMAL 32-BIT STRICT: Pre-checking overflow without 64-bit integers
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    int myAtoiStrict32Bit(string s)
    {
        int i = 0, n = s.length();
        int sign = 1;
        int result = 0; // Strictly 32-bit signed integer

        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Accumulate digits with strict pre-overflow checking
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};

int main()
{
    Solution obj;
    string s1 = "   -42";
    string s2 = "4193 with words";
    string s3 = "  -91283472332"; 

    

    cout << "Input: \"" << s1 << "\" -> Output: " << obj.myAtoiStrict32Bit(s1) << "\n";
    cout << "Input: \"" << s2 << "\" -> Output: " << obj.myAtoiStrict32Bit(s2) << "\n";
    cout << "Input: \"" << s3 << "\" -> Output: " << obj.myAtoiStrict32Bit(s3) << "\n";

    return 0;
}