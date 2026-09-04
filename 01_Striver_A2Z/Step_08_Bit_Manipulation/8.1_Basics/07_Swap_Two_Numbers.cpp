#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Bitwise XOR Swap
    // Time Complexity: O(1) | Space Complexity: O(1)
    void swapNumber(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main()
{
    Solution obj;
    int a = 10;
    int b = 25;

    cout << "Before swap: a = " << a << ", b = " << b << "\n";

    obj.swapNumber(a, b);

    cout << "After swap: a = " << a << ", b = " << b << "\n";

    return 0;
}