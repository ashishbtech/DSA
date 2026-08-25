#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function that handles the pure recursive math
    double powerHelper(double x, long long n)
    {
        // Base Case: Anything to the power of 0 is 1
        if (n == 0)
            return 1.0;

        // Divide and Conquer
        double halfPower = powerHelper(x, n / 2);

        // If n is even: (x^(n/2)) * (x^(n/2))
        if (n % 2 == 0)
        {
            return halfPower * halfPower;
        }
        // If n is odd: x * (x^(n/2)) * (x^(n/2))
        else
        {
            return x * halfPower * halfPower;
        }
    }

public:
    // 1. BRUTE FORCE: O(N) Time (Will TLE on LeetCode)
    double myPowBrute(double x, int n)
    {
        double ans = 1.0;
        long long nn = n; // Use long long to avoid overflow when converting negative to positive

        if (nn < 0)
            nn = -nn;

        for (long long i = 0; i < nn; i++)
        {
            ans = ans * x;
        }

        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }

    // 2. OPTIMAL: O(log N) Time using Binary Exponentiation
    double myPowOptimal(double x, int n)
    {
        // Copy to a 64-bit integer to safely handle n = INT_MIN
        long long nn = n;

        // If the power is negative, we can just invert x and make the power positive
        if (nn < 0)
        {
            x = 1.0 / x;
            nn = -nn;
        }

        return powerHelper(x, nn);
    }
};

int main()
{
    Solution obj;

    double x1 = 2.0;
    int n1 = 10;
    double x2 = 2.1;
    int n2 = 3;
    double x3 = 2.0;
    int n3 = -2;

    cout << x1 << "^" << n1 << " = " << obj.myPowOptimal(x1, n1) << "\n";
    cout << x2 << "^" << n2 << " = " << obj.myPowOptimal(x2, n2) << "\n";
    cout << x3 << "^" << n3 << " = " << obj.myPowOptimal(x3, n3) << "\n";

    return 0;
}