#include <iostream>
using namespace std;

class Solution {
public:
    // Pattern 10: Half Diamond / Rotated Triangle
    void printPattern10(int n) {
        for (int i = 1; i <= 2 * n - 1; i++) {
            int stars = i;
            if (i > n) stars = 2 * n - i;
            for (int j = 0; j < stars; j++) cout << "*";
            cout << endl;
        }
    }

    // Pattern 11: Binary Number Triangle
    void printPattern11(int n) {
        int start = 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) start = 1;
            else start = 0;
            for (int j = 0; j <= i; j++) {
                cout << start << " ";
                start = 1 - start;
            }
            cout << endl;
        }
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "--- Pattern 10 ---" << endl; obj.printPattern10(n);
    cout << "--- Pattern 11 ---" << endl; obj.printPattern11(n);
    return 0;
}