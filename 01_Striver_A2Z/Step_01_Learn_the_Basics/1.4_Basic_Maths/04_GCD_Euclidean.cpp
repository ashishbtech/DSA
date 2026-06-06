#include <iostream>
using namespace std;

class Solution {
public:
    // Optimal Euclidean Algorithm
    int findGCD(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) a = a % b;
            else b = b % a;
        }
        if (a == 0) return b;
        return a;
    }
};

int main() {
    Solution obj;
    int a = 52, b = 10;
    cout << "GCD of " << a << " and " << b << " is: " << obj.findGCD(a, b) << endl;
    return 0;
}