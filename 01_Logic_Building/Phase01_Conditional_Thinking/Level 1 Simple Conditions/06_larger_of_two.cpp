//Take two numbers and print the larger one

#include <iostream>
using namespace std;

class Solution {
public:
    int largerNumber(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }
};

int main() {
    Solution obj;

    int a, b;
    cin >> a >> b;

    cout << obj.largerNumber(a, b);

    return 0;
}