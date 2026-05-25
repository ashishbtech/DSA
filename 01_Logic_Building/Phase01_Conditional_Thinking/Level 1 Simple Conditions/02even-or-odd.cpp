//Check if a number is even or odd. 
#include <iostream>
using namespace std;

class Solution {
public:
    string evenOdd(int n) {
        if (n % 2 == 0)
            return "Even";
        else
            return "Odd";
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.evenOdd(n);

    return 0;
}