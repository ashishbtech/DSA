#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Brian Kernighan's Algorithm logic
    // Time Complexity: O(1) | Space Complexity: O(1)
    bool isPowerOfTwo(int n)
    {
        // A power of 2 must be strictly greater than 0.
        // n & (n - 1) removes the rightmost set bit. If it was a power of 2,
        // removing that single set bit will leave us with 0.
        if (n > 0 && (n & (n - 1)) == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    int n1 = 16;
    int n2 = 18;

    if (obj.isPowerOfTwo(n1))
        cout << n1 << " is a power of 2.\n";
    else
        cout << n1 << " is NOT a power of 2.\n";

    if (obj.isPowerOfTwo(n2))
        cout << n2 << " is a power of 2.\n";
    else
        cout << n2 << " is NOT a power of 2.\n";

    return 0;
}