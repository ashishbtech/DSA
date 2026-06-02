#include <iostream>
using namespace std;

class Solution {
public:
    // Pattern 12: Number Crown
    void printPattern12(int n) {
        int spaces = 2 * (n - 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) cout << j;
            for (int j = 1; j <= spaces; j++) cout << " ";
            for (int j = i; j >= 1; j--) cout << j;
            cout << endl;
            spaces -= 2;
        }
    }

    // Pattern 13: Increasing Number Triangle
    void printPattern13(int n) {
        int num = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << num << " ";
                num++;
            }
            cout << endl;
        }
    }

    // Pattern 14: Letter Triangle
    void printPattern14(int n) {
        for (int i = 0; i < n; i++) {
            for (char ch = 'A'; ch <= 'A' + i; ch++) cout << ch << " ";
            cout << endl;
        }
    }

    // Pattern 15: Inverted Letter Triangle
    void printPattern15(int n) {
        for (int i = 0; i < n; i++) {
            for (char ch = 'A'; ch < 'A' + (n - i); ch++) cout << ch << " ";
            cout << endl;
        }
    }

    // Pattern 16: Alpha-Row Triangle
    void printPattern16(int n) {
        for (int i = 0; i < n; i++) {
            char ch = 'A' + i;
            for (int j = 0; j <= i; j++) cout << ch << " ";
            cout << endl;
        }
    }

    // Pattern 17: Alpha-Hill Pyramid
    void printPattern17(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) cout << " ";
            char ch = 'A';
            int breakpoint = (2 * i + 1) / 2;
            for (int j = 1; j <= 2 * i + 1; j++) {
                cout << ch;
                if (j <= breakpoint) ch++;
                else ch--;
            }
            cout << endl;
        }
    }

    // Pattern 18: Reverse Letter Triangle
    void printPattern18(int n) {
        for (int i = 0; i < n; i++) {
            for (char ch = ('A' + n - 1) - i; ch <= 'A' + n - 1; ch++) {
                cout << ch << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "--- Pattern 12 ---" << endl; obj.printPattern12(n);
    cout << "--- Pattern 13 ---" << endl; obj.printPattern13(n);
    cout << "--- Pattern 14 ---" << endl; obj.printPattern14(n);
    cout << "--- Pattern 15 ---" << endl; obj.printPattern15(n);
    cout << "--- Pattern 16 ---" << endl; obj.printPattern16(n);
    cout << "--- Pattern 17 ---" << endl; obj.printPattern17(n);
    cout << "--- Pattern 18 ---" << endl; obj.printPattern18(n);
    return 0;
}