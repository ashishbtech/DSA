#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: XOR followed by Brian Kernighan's Algorithm
    // Time Complexity: O(K) where K is the number of different bits | Space: O(1)
    int minBitFlips(int start, int goal)
    {
        // XOR gives us a number where only the differing bits are set to 1
        int xorResult = start ^ goal;
        int count = 0;

        // Count the set bits
        while (xorResult != 0)
        {
            xorResult = xorResult & (xorResult - 1);
            count++;
        }

        return count;
    }
};

int main()
{
    Solution obj;
    int start = 10; // Binary: 1010
    int goal = 7;   // Binary: 0111

    cout << "Minimum bits to flip to convert " << start << " to " << goal << " is: ";
    cout << obj.minBitFlips(start, goal) << "\n";

    return 0;
}