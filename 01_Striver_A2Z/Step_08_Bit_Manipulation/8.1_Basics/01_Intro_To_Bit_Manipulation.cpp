#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // OPTIMAL: Bitwise operations execute in O(1) time and O(1) space
    void bitManipulation(int num, int i) {
        
        int mask = 1 << (i - 1);
        
        // Get
        int getBit = (num & mask) != 0 ? 1 : 0;
        
        // Set
        int setBit = num | mask;
        
        // Clear
        int clearBit = num & ~mask;
        
        cout << getBit << " " << setBit << " " << clearBit << endl;
    }
};

int main() {
    Solution obj;
    int num = 70; // Binary: 1000110
    int i = 3;    // 3rd bit from the right (1-based)
    
    obj.bitManipulation(num, i);
    
    return 0;
}