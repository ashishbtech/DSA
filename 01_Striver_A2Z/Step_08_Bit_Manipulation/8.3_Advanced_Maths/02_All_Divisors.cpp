#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Iterate from 1 to N
    // Time Complexity: O(N) | Space Complexity: O(K)
    vector<int> printDivisorsBrute(int n)
    {
        vector<int> divisors;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);
            }
        }
        return divisors;
    }

    // OPTIMAL: Iterate up to sqrt(N)
    // Time Complexity: O(sqrt(N) + K log K) | Space Complexity: O(K)
    vector<int> printDivisorsOptimal(int n)
    {
        vector<int> divisors;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);

                if ((n / i) != i)
                {
                    divisors.push_back(n / i);
                }
            }
        }

        sort(divisors.begin(), divisors.end());

        return divisors;
    }
};

int main()
{
    Solution obj;
    int n = 36;

    cout << "Brute Force divisors of " << n << ":\n";
    vector<int> bruteAns = obj.printDivisorsBrute(n);
    for (int div : bruteAns)
        cout << div << " ";
    cout << "\n\n";

    cout << "Optimal divisors of " << n << ":\n";
    vector<int> optimalAns = obj.printDivisorsOptimal(n);
    for (int div : optimalAns)
        cout << div << " ";
    cout << "\n";

    return 0;
}