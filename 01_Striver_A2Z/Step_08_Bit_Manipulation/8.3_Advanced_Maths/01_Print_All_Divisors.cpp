#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper
    bool isPrime(int num)
    {
        if (num <= 1)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

public:
    // BRUTE FORCE: Check every number and verify if it is prime
    // Time Complexity: O(N * sqrt(N))
    vector<int> primeFactorsBrute(int n)
    {
        vector<int> factors;
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                if (isPrime(i))
                {
                    factors.push_back(i);
                }
            }
        }
        return factors;
    }

    // OPTIMAL: Divide out prime factors up to sqrt(N)
    // Time Complexity: O(sqrt(N))
    vector<int> primeFactorsOptimal(int n)
    {
        vector<int> factors;

        for (int i = 2; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                factors.push_back(i);

                // Strip all occurrences of this prime factor from N
                while (n % i == 0)
                {
                    n = n / i;
                }
            }
        }

        // If n is not 1 after the loop, the remaining n is a prime number itself
        if (n > 1)
        {
            factors.push_back(n);
        }

        return factors;
    }
};

int main()
{
    Solution obj;
    int n1 = 36;
    int n2 = 35;

    cout << "Optimal prime factors of " << n1 << ": ";
    vector<int> ans1 = obj.primeFactorsOptimal(n1);
    for (int num : ans1)
        cout << num << " ";
    cout << "\n";

    cout << "Optimal prime factors of " << n2 << ": ";
    vector<int> ans2 = obj.primeFactorsOptimal(n2);
    for (int num : ans2)
        cout << num << " ";
    cout << "\n";

    return 0;
}