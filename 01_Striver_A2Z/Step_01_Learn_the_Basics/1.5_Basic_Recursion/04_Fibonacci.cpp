#include <iostream>
using namespace std;

class Solution {
public:
    // Multiple Recursion Calls
    int fibonacci(int n) {
        if (n <= 1) return n; // Base Cases: fib(0) = 0, fib(1) = 1
        
        int last = fibonacci(n - 1);
        int slast = fibonacci(n - 2);
        
        return last + slast;
    }
};

int main() {
    Solution obj;
    int n = 6; // Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8...
    
    cout << "The " << n << "th Fibonacci number is: " << obj.fibonacci(n) << endl;
    
    return 0;
}