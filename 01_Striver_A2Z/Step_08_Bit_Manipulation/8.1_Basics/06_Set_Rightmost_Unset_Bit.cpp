#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: n | (n + 1) trick
    // Time Complexity: O(1) | Space Complexity: O(1)
    int setBits(int n)
    {
        // Edge case: If all bits are already set (e.g., 7 -> 111),
        // n & (n + 1) will be 0. We just return the original number.
        if ((n & (n + 1)) == 0)
        {
            return n;
        }

        // Otherwise, ORing n with n + 1 sets the rightmost unset bit
        return n | (n + 1);
    }
};

int main()
{
    Solution obj;
    int n1 = 5;  // Binary: 101 -> Should become 111 (7)
    int n2 = 10; // Binary: 1010 -> Should become 1011 (11)
    int n3 = 7;  // Binary: 111 -> All bits set, should remain 111 (7)

    cout << n1 << " becomes " << obj.setBits(n1) << "\n";
    cout << n2 << " becomes " << obj.setBits(n2) << "\n";
    cout << n3 << " becomes " << obj.setBits(n3) << "\n";

    return 0;
}