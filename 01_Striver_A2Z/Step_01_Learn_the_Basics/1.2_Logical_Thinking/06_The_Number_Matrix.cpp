#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Pattern 22: Concentric Shrinking Number Matrix
    void printPattern22(int n) {
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                int top = i;
                int left = j;
                int right = (2 * n - 2) - j;
                int bottom = (2 * n - 2) - i;
                
                // Value is calculated by subtracting the min distance to any edge from n
                cout << (n - min({top, left, right, bottom})) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution obj;
    int n = 4;
    cout << "--- Pattern 22 ---" << endl; 
    obj.printPattern22(n);
    return 0;
}