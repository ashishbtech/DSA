#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper
    bool checkPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    // BRUTE FORCE
    // Time: O(N * sqrt(N)) | Space: O(1)
    int countPrimesBrute(int n)
    {
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (checkPrime(i))
            {
                count++;
            }
        }
        return count;
    }

    // OPTIMAL: Sieve of Eratosthenes
    // Time: O(N log log N) | Space: O(N)
    int countPrimesOptimal(int n)
    {
        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        int count = 0;

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                // Mark all multiples as false starting from i * i
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        // Count the remaining true values
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;
    int n = 30;

    cout << obj.countPrimesBrute(n) << "\n";
    cout << obj.countPrimesOptimal(n) << "\n";

    return 0;
}