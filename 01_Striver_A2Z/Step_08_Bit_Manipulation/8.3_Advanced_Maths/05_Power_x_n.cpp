#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Multiply x, n times
    // Time Complexity: O(N) | Space Complexity: O(1)
    double myPowBrute(double x, int n)
    {
        double ans = 1.0;

        // Prevent integer overflow for INT_MIN
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;

        for (long long i = 0; i < nn; i++)
        {
            ans = ans * x;
        }

        if (n < 0)
            ans = 1.0 / ans;
        return ans;
    }

    // OPTIMAL: Binary Exponentiation
    // Time Complexity: O(log N) | Space Complexity: O(1)
    double myPowOptimal(double x, int n)
    {
        double ans = 1.0;

        // Prevent integer overflow for INT_MIN
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;

        while (nn > 0)
        {
            if (nn % 2 == 1)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }

        if (n < 0)
            ans = 1.0 / ans;
        return ans;
    }
};

int main()
{
    Solution obj;
    double x = 2.00000;
    int n = 10;

    cout << obj.myPowBrute(x, n) << "\n";
    cout << obj.myPowOptimal(x, n) << "\n";

    x = 2.00000;
    n = -2;
    cout << obj.myPowOptimal(x, n) << "\n";

    return 0;
}