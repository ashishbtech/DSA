#include <iostream>
using namespace std;

class Solution {
public:
    void displaySizes() {
        cout << "Size of int: " << sizeof(int) << " bytes\n";
        cout << "Size of long: " << sizeof(long) << " bytes\n";
        cout << "Size of long long: " << sizeof(long long) << " bytes\n";
        cout << "Size of float: " << sizeof(float) << " bytes\n";
        cout << "Size of double: " << sizeof(double) << " bytes\n";
        cout << "Size of char: " << sizeof(char) << " byte\n";
    }
};

int main() {
    Solution obj;
    cout << "--- Data Types & Memory ---" << endl;
    obj.displaySizes();
    return 0;
}