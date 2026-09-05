#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function
    int xor1toN(int n)
    {
        if (n % 4 == 0)
            return n;
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        if (n % 4 == 3)
            return 0;
        return 0;
    }

public:
    // OPTIMAL: Prefix XOR property combined with mathematical pattern
    // Time Complexity: O(1) | Space Complexity: O(1)
    int findXOR(int l, int r)
    {
        // XOR(L to R) = XOR(1 to L-1) ^ XOR(1 to R)
        return xor1toN(l - 1) ^ xor1toN(r);
    }
};

int main()
{
    Solution obj;
    int L = 4;
    int R = 7;

    cout << "XOR of numbers from " << L << " to " << R << " is: " << obj.findXOR(L, R) << "\n";

    return 0;
}