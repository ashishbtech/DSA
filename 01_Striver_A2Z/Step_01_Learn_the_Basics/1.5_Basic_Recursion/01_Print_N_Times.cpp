#include <iostream>
using namespace std;

class Solution {
public:
    // Print Name N times
    void printName(int i, int n) {
        if (i > n) return; // Base Case
        cout << "Ashish" << " ";
        printName(i + 1, n);
    }

    // Print 1 to N
    void print1ToN(int i, int n) {
        if (i > n) return;
        cout << i << " ";
        print1ToN(i + 1, n);
    }

    // Print N to 1
    void printNTo1(int i, int n) {
        if (i < 1) return;
        cout << i << " ";
        printNTo1(i - 1, n);
    }
    
    // Print 1 to N (Using Backtracking - calling before printing)
    void print1ToN_Backtrack(int i, int n) {
        if (i < 1) return;
        print1ToN_Backtrack(i - 1, n);
        cout << i << " ";
    }
};

int main() {
    Solution obj;
    int n = 4;
    
    cout << "Names: "; obj.printName(1, n); cout << endl;
    cout << "1 to N: "; obj.print1ToN(1, n); cout << endl;
    cout << "N to 1: "; obj.printNTo1(n, n); cout << endl;
    cout << "1 to N (Backtrack): "; obj.print1ToN_Backtrack(n, n); cout << endl;
    
    return 0;
}