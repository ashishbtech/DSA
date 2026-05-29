#include <iostream>
using namespace std;

class Solution {
public:
    // Pattern 7: Star Pyramid
    void printPattern7(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) cout << " ";
            for (int j = 0; j < 2 * i + 1; j++) cout << "*";
            cout << endl;
        }
    }

    // Pattern 8: Inverted Star Pyramid
    void printPattern8(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) cout << " ";
            for (int j = 0; j < 2 * n - (2 * i + 1); j++) cout << "*";
            cout << endl;
        }
    }

    // Pattern 9: Diamond Star Pattern
    void printPattern9(int n) {
        printPattern7(n);
        printPattern8(n);
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "--- Pattern 7 ---" << endl; obj.printPattern7(n);
    cout << "--- Pattern 8 ---" << endl; obj.printPattern8(n);
    cout << "--- Pattern 9 ---" << endl; obj.printPattern9(n);
    return 0;
}