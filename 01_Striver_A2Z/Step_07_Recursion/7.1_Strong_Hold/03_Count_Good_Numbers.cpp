#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long MOD = 1e9 + 7;

    long long powerHelper(long long base, long long exp)
    {
        // Base case: Any number to power 0 is 1
        if (exp == 0)
            return 1;

        // Divide and Conquer
        long long half = powerHelper(base, exp / 2);

        // Calculate half * half and apply modulo to prevent overflow
        long long half_squared = (half * half) % MOD;

        // If exponent is even
        if (exp % 2 == 0)
        {
            return half_squared;
        }
        // If exponent is odd
        else
        {
            return (base * half_squared) % MOD;
        }
    }

public:
    // 1. BRUTE FORCE: O(N) Loop (Will TLE)
    int countGoodNumbersBrute(long long n)
    {
        long long ans = 1;
        for (long long i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans = (ans * 5) % MOD; // Even index -> 5 choices
            }
            else
            {
                ans = (ans * 4) % MOD; // Odd index -> 4 choices
            }
        }
        return ans;
    }

    // 2. OPTIMAL: O(log N) Recursive Exponentiation
    int countGoodNumbersOptimal(long long n)
    {
        // Calculate the number of even and odd indices
        long long even_indices = (n + 1) / 2;
        long long odd_indices = n / 2;

        // Calculate 5^(even_indices) % MOD
        long long even_combos = powerHelper(5, even_indices);

        // Calculate 4^(odd_indices) % MOD
        long long odd_combos = powerHelper(4, odd_indices);

        // Multiply them and take modulo one last time
        return (even_combos * odd_combos) % MOD;
    }
};

int main()
{
    Solution obj;

    long long n1 = 1;
    long long n2 = 4;
    long long n3 = 50;

    cout << "n = " << n1 << " -> Output: " << obj.countGoodNumbersOptimal(n1) << "\n";
    cout << "n = " << n2 << " -> Output: " << obj.countGoodNumbersOptimal(n2) << "\n";
    cout << "n = " << n3 << " -> Output: " << obj.countGoodNumbersOptimal(n3) << "\n";

    return 0;
}