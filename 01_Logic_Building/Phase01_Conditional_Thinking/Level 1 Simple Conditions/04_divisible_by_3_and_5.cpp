//Check if a number is divisible by both 3 and 5

#include <iostream>
using namespace std;

class Solution {
public:
    string checkDivisible(int n) {
        if (n % 3 == 0 && n % 5 == 0)
            return "Divisible by both 3 and 5";
        else
            return "Not divisible by both 3 and 5";
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.checkDivisible(n);

    return 0;
}