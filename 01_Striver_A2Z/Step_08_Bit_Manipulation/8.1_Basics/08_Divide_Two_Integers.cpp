#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Simulating division using bitwise left-shift (Powers of 2)
    // Time Complexity: O(log^2 N) | Space Complexity: O(1)
    int divide(int dividend, int divisor)
    {
        // Edge case: 32-bit signed integer overflow
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        // Determine the sign of the final quotient
        bool isPositive = (dividend >= 0) == (divisor >= 0);

        // Convert to absolute values using long long to prevent INT_MIN absolute overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        // Keep reducing the dividend until it's smaller than the divisor
        while (n >= d)
        {
            int count = 0;

            // Find the maximum power of 2 we can multiply the divisor by
            // without exceeding the current dividend
            while (n >= (d << (count + 1)))
            {
                count++;
            }

            // Add that power of 2 to our quotient
            quotient = quotient + (1LL << count);

            // Subtract the massive chunk we just calculated from the dividend
            n = n - (d << count);
        }

        // Apply the pre-calculated sign
        if (!isPositive)
        {
            quotient = -quotient;
        }

        return quotient;
    }
};

int main()
{
    Solution obj;
    int dividend = 10;
    int divisor = 3;

    cout << dividend << " / " << divisor << " = " << obj.divide(dividend, divisor) << "\n";

    dividend = 43;
    divisor = -8;
    cout << dividend << " / " << divisor << " = " << obj.divide(dividend, divisor) << "\n";

    return 0;
}