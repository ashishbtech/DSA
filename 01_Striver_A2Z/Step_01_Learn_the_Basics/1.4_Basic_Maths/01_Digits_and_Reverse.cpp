#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Approach 1: Standard extraction O(log10(N))
    int countDigits(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = n / 10;
        }
        return count;
    }

    // Approach 2: Optimal Math extraction O(1)
    int countDigitsOptimal(int n) {
        if (n == 0) return 1;
        return (int)(log10(n) + 1);
    }

    int reverseNumber(int n) {
        int revNum = 0;
        while (n > 0) {
            int lastDigit = n % 10;
            revNum = (revNum * 10) + lastDigit;
            n = n / 10;
        }
        return revNum;
    }
};

int main() {
    Solution obj;
    int num = 7789;
    cout << "Number: " << num << endl;
    cout << "Digit Count: " << obj.countDigitsOptimal(num) << endl;
    cout << "Reversed: " << obj.reverseNumber(num) << endl;
    return 0;
}