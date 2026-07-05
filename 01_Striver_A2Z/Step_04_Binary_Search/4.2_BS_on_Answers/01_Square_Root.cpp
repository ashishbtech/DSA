#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Linear search testing every number
    // Time Complexity: O(N) | Space Complexity: O(1)
    int floorSqrtBrute(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int ans = 1;
        for (long long i = 1; i <= n; i++)
        {
            if (i * i <= n)
            {
                ans = i;
            }
            else
            {
                break;
            }
        }
        return ans;
    }

    // 2. OPTIMAL: Binary Search on the Answer Space
    // Time Complexity: O(log N) | Space Complexity: O(1)
    int floorSqrtOptimal(int n)
    {
        if (n == 0 || n == 1)
            return n;

        long long low = 1, high = n;
        int ans = 1;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    // 3. STL CHEAT CODE: For Competitive Programming
    // Time Complexity: O(1) natively via hardware floating point ops
    int floorSqrtSTL(int n)
    {
        return sqrt(n);
    }
};

int main()
{
    Solution obj;
    int n = 28; // Square root is 5.29... Floor is 5.

    cout << "1. Brute Force : " << obj.floorSqrtBrute(n) << "\n";
    cout << "2. Optimal     : " << obj.floorSqrtOptimal(n) << "\n";
    cout << "3. STL Built-in: " << obj.floorSqrtSTL(n) << "\n";

    return 0;
}