#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        int original = n;
        int revNum = 0;
        while (n > 0) {
            int lastDigit = n % 10;
            revNum = (revNum * 10) + lastDigit;
            n = n / 10;
        }
        return original == revNum;
    }

    bool isArmstrong(int n) {
        int original = n;
        int sum = 0;
        int k = to_string(n).length(); // Number of digits
        
        while (n > 0) {
            int lastDigit = n % 10;
            sum += pow(lastDigit, k);
            n = n / 10;
        }
        return sum == original;
    }
};

int main() {
    Solution obj;
    int pNum = 121;
    int aNum = 153; // 1^3 + 5^3 + 3^3 = 153
    
    cout << pNum << " is Palindrome? " << (obj.isPalindrome(pNum) ? "Yes" : "No") << endl;
    cout << aNum << " is Armstrong? " << (obj.isArmstrong(aNum) ? "Yes" : "No") << endl;
    return 0;
}