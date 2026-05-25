//Take a number and print whether it’s positive, negative, or zero

#include <iostream>
using namespace std;

class Solution {
public:
    string checkNumber(int n) {
        if (n > 0)
            return "Positive";
        else if (n < 0)
            return "Negative";
        else
            return "Zero";
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.checkNumber(n);

    return 0;
}