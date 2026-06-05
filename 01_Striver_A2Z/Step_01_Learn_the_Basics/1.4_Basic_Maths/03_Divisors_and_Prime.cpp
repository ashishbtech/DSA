#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Optimal Divisors: O(sqrt(N))
    void printAllDivisors(int n) {
        cout << "Divisors of " << n << ": ";
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cout << i << " ";
                if (i != n / i) {
                    cout << n / i << " ";
                }
            }
        }
        cout << endl;
    }

    // Optimal Prime Check: O(sqrt(N))
    bool isPrime(int n) {
        if (n <= 1) return false;
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                if (n / i != i) count++;
            }
        }
        return count == 2; // Prime numbers only have exactly 2 divisors (1 and itself)
    }
};

int main() {
    Solution obj;
    obj.printAllDivisors(36);
    cout << "Is 17 Prime? " << (obj.isPrime(17) ? "Yes" : "No") << endl;
    return 0;
}