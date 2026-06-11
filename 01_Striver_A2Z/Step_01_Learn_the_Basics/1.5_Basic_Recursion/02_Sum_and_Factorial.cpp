#include <iostream>
using namespace std;

class Solution {
public:
    // Parameterized Recursion
    void sumParameterized(int i, int sum) {
        if (i < 1) {
            cout << "Sum (Parameterized): " << sum << endl;
            return;
        }
        sumParameterized(i - 1, sum + i);
    }

    // Functional Recursion (Returning the value)
    int sumFunctional(int n) {
        if (n == 0) return 0;
        return n + sumFunctional(n - 1);
    }

    // Factorial (Functional)
    int factorial(int n) {
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
    }
};

int main() {
    Solution obj;
    int n = 5; // Sum should be 15, Factorial should be 120
    
    obj.sumParameterized(n, 0);
    cout << "Sum (Functional): " << obj.sumFunctional(n) << endl;
    cout << "Factorial: " << obj.factorial(n) << endl;
    
    return 0;
}