#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Iterative Loop
    // Time Complexity: O(i) | Space Complexity: O(1)
    int countNodesBrute(int i)
    {
        int nodes = 1;
        for (int level = 1; level < i; level++)
        {
            nodes = nodes * 2;
        }
        return nodes;
    }

    // 2. BETTER APPROACH: Math Pow Function
    // Time Complexity: O(1) | Space Complexity: O(1)
    // Note: pow() returns a double, so it is cast to int.
    int countNodesBetter(int i)
    {
        return (int)pow(2, i - 1);
    }

    // 3. OPTIMAL APPROACH: Bitwise Left Shift
    // Time Complexity: O(1) | Space Complexity: O(1)
    int countNodes(int i)
    {
        return 1 << (i - 1);
    }
};

int main()
{
    Solution obj;
    int level = 5;

    cout << "--- Level " << level << " ---\n";
    cout << "Brute Force : " << obj.countNodesBrute(level) << "\n";
    cout << "Better (pow): " << obj.countNodesBetter(level) << "\n";
    cout << "Optimal (<<): " << obj.countNodes(level) << "\n";

    return 0;
}