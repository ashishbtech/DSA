//Take three numbers and print the largest

#include <iostream>
using namespace std;

class Solution {
public:
    int largestNumber(int a, int b, int c) {
        if (a >= b && a >= c)
            return a;
        else if (b >= a && b >= c)
            return b;
        else
            return c;
    }
};

int main() {
    Solution obj;

    int a, b, c;
    cin >> a >> b >> c;

    cout << obj.largestNumber(a, b, c);

    return 0;
}