#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE / BETTER: Solves a single query
    // Time: O(sqrt(N)) | Space: O(log N) to store factors
    vector<int> primeFactorsBrute(int n)
    {
        vector<int> factors;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                factors.push_back(i);
                n = n / i;
            }
        }
        if (n > 1)
        {
            factors.push_back(n);
        }
        return factors;
    }

    // OPTIMAL: Smallest Prime Factor (SPF) Sieve
    // Time: O(N log log N) precomputation + O(log N) per query
    vector<int> primeFactorsOptimal(int n)
    {

        int MAX_N = n + 1;
        vector<int> spf(MAX_N);

        // Initialize SPF of every number to itself
        for (int i = 1; i < MAX_N; i++)
        {
            spf[i] = i;
        }

        // Generate SPF array using Sieve logic
        for (int i = 2; i * i < MAX_N; i++)
        {
            if (spf[i] == i)
            { // If 'i' is prime
                for (int j = i * i; j < MAX_N; j += i)
                {
                    // Update SPF only if it hasn't been updated by a smaller prime yet
                    if (spf[j] == j)
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        // Extract factors in O(log N) time
        vector<int> factors;
        while (n != 1)
        {
            factors.push_back(spf[n]);
            n = n / spf[n]; // Divide N by its smallest prime factor
        }

        return factors;
    }
};

int main()
{
    Solution obj;
    int n = 120;

    vector<int> brute = obj.primeFactorsBrute(n);
    for (int x : brute)
        cout << x << " ";
    cout << "\n";

    vector<int> optimal = obj.primeFactorsOptimal(n);
    for (int x : optimal)
        cout << x << " ";
    cout << "\n";

    return 0;
}