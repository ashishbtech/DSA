#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Right-shift approach to prevent integer overflow
    // Time Complexity: O(1) | Space Complexity: O(1)
    bool checkKthBitRighttShift(int n, int k)
    {

        if (((n >> k) & 1) == 1)
        {
            return true;
        }
        return false;
    }

    // OPTIMAL: Left-shift approach (with 1LL to prevent 32-bit overflow)
    // Time Complexity: O(1) | Space Complexity: O(1)
    bool checkKthBitLeftShift(int n, int k)
    {

        int mask = 1 << k;

        if ((n & mask) != 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    int n = 4; // Binary: 100
    int k = 2; // 0-based index

    if (obj.checkKthBitLeftShift(n, k))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
    if (obj.checkKthBitRighttShift(n, k))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}