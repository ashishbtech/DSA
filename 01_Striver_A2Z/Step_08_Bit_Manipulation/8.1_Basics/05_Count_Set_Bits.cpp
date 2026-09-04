#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Brian Kernighan's Algorithm
    // Time Complexity: O(K) where K is the number of set bits | Space: O(1)
    int hammingWeight(int n)
    {
        int count = 0;

        while (n != 0)
        {
            // Remove the rightmost set bit
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

int main()
{
    Solution obj;

    // int n = 11; // Binary: 1011
    int n = 32;

    cout << "Number of set bits in " << n << " is: " << obj.hammingWeight(n) << "\n";

    return 0;
}