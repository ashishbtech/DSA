#include <iostream>
using namespace std;

class Solution {
public:
    // Pattern 1: Solid Square
    void printPattern1(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << "* ";
            cout << endl;
        }
    }

    // Pattern 2: Right-Angled Triangle
    void printPattern2(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) cout << "* ";
            cout << endl;
        }
    }

    // Pattern 3: Right-Angled Number Triangle
    void printPattern3(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) cout << j << " ";
            cout << endl;
        }
    }

    // Pattern 4: Right-Angled Row-Number Triangle
    void printPattern4(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) cout << i << " ";
            cout << endl;
        }
    }

    // Pattern 5: Inverted Right-Angled Triangle
    void printPattern5(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) cout << "* ";
            cout << endl;
        }
    }

    // Pattern 6: Inverted Number Triangle
    void printPattern6(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) cout << j << " ";
            cout << endl;
        }
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "--- Pattern 1 ---" << endl; obj.printPattern1(n);
    cout << "--- Pattern 2 ---" << endl; obj.printPattern2(n);
    cout << "--- Pattern 3 ---" << endl; obj.printPattern3(n);
    cout << "--- Pattern 4 ---" << endl; obj.printPattern4(n);
    cout << "--- Pattern 5 ---" << endl; obj.printPattern5(n);
    cout << "--- Pattern 6 ---" << endl; obj.printPattern6(n);
    return 0;
}