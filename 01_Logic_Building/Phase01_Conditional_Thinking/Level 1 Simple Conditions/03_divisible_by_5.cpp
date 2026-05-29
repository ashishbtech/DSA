//Check if a number is divisible by 5

#include <iostream>
using namespace std;

class Solution {
public:
    string checkDivisible(int n) {
        if (n % 5 == 0)
            return "Divisible by 5";
        else
            return "Not divisible by 5";
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.checkDivisible(n);

    return 0;
}