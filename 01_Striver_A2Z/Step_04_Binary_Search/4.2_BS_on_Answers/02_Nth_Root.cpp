#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int checkNthRoot(int mid, int n, int m)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * mid;

            if (ans > m)
                return 2;
        }
        if (ans == m)
            return 1;
        return 0;
    }

public:
    // 1. BRUTE FORCE: Linear search testing every number
    // Time Complexity: O(M * N) worst case | Space Complexity: O(1)
    int NthRootBrute(int n, int m)
    {
        for (int i = 1; i <= m; i++)
        {
            int val = checkNthRoot(i, n, m);
            if (val == 1)
                return i;
            if (val == 2)
                break;
        }
        return -1;
    }

    // 2. OPTIMAL: Binary Search with Early Exit Helper
    // Time Complexity: O(log M * N) | Space Complexity: O(1)
    int NthRootOptimal(int n, int m)
    {
        int low = 1, high = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int status = checkNthRoot(mid, n, m);

            if (status == 1)
            {
                return mid;
            }
            else if (status == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    int n = 3;
    int m = 27;

    cout << "Brute Force : " << obj.NthRootBrute(n, m) << "\n";
    cout << "Optimal     : " << obj.NthRootOptimal(n, m) << "\n";

    // testing a failed case..................................................................................././,:-)
    int n2 = 4, m2 = 69;
    cout << "\nTesting " << n2 << "th root of " << m2 << ": " << obj.NthRootOptimal(n2, m2) << " (Expected -1)\n";

    return 0;
}