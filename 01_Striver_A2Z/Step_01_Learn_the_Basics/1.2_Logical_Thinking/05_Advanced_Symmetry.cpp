#include <iostream>
using namespace std;

class Solution {
public:
    // Pattern 19: Symmetric Void
    void printPattern19(int n) {
        // Top Half
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) cout << "*";
            for (int j = 0; j < 2 * i; j++) cout << " ";
            for (int j = 1; j <= n - i; j++) cout << "*";
            cout << endl;
        }
        // Bottom Half
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= i + 1; j++) cout << "*";
            for (int j = 0; j < 2 * (n - i - 1); j++) cout << " ";
            for (int j = 1; j <= i + 1; j++) cout << "*";
            cout << endl;
        }
    }

    // Pattern 20: Butterfly Pattern
    void printPattern20(int n) {
        int spaces = 2 * n - 2;
        for (int i = 1; i <= 2 * n - 1; i++) {
            int stars = i;
            if (i > n) stars = 2 * n - i;
            
            for (int j = 1; j <= stars; j++) cout << "*";
            for (int j = 1; j <= spaces; j++) cout << " ";
            for (int j = 1; j <= stars; j++) cout << "*";
            
            cout << endl;
            if (i < n) spaces -= 2;
            else spaces += 2;
        }
    }

    // Pattern 21: Hollow Square Frame
    void printPattern21(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) cout << "*";
                else cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "--- Pattern 19 ---" << endl; obj.printPattern19(n);
    cout << "--- Pattern 20 ---" << endl; obj.printPattern20(n);
    cout << "--- Pattern 21 ---" << endl; obj.printPattern21(n);
    return 0;
}