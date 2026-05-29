#include <iostream>
using namespace std;

class Solution {
public:
    // Pass by Value (Creates a copy, original is untouched)
    void passByValue(int num) {
        num += 10;
    }

    // Pass by Reference (Uses memory address, original is modified)
    void passByReference(int &num) {
        num += 10;
    }
};

int main() {
    Solution obj;
    
    int val1 = 5;
    obj.passByValue(val1);
    cout << "After Pass by Value: " << val1 << " (Unchanged)" << endl;

    int val2 = 5;
    obj.passByReference(val2);
    cout << "After Pass by Reference: " << val2 << " (Modified)" << endl;

    return 0;
}