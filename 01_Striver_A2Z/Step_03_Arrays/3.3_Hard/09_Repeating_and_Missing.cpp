#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. BRUTE FORCE: For every number from 1 to N, count its occurrences in the array
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    vector<int> findMissingRepeatingBrute(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == i) cnt++;
            }
            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;

            if (repeating != -1 && missing != -1) break;
        }
        return {repeating, missing};
    }

    // 2. BETTER: Use a frequency array (Hash Array)
    // Time Complexity: O(2N) | Space Complexity: O(N)
    vector<int> findMissingRepeatingBetter(vector<int>& arr) {
        int n = arr.size();
        vector<int> hash(n + 1, 0);
        int repeating = -1, missing = -1;

        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) repeating = i;
            else if (hash[i] == 0) missing = i;

            if (repeating != -1 && missing != -1) break;
        }
        return {repeating, missing};
    }

    // 3. OPTIMAL 1: Mathematical Equations (S and S2)
    // Time Complexity: O(N) | Space Complexity: O(1)
    vector<int> findMissingRepeatingMath(vector<int>& arr) {
        long long n = arr.size();
        
        // Expected sum of first N natural numbers and their squares
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        // Actual sum of the array and their squares
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }

        // Let X be the repeating number, Y be the missing number
        // Equation 1: S - SN = X - Y
        long long val1 = S - SN; 

        // Equation 2: S2 - S2N = X^2 - Y^2 = (X - Y)(X + Y)
        long long val2 = S2 - S2N; 
        
        // Find X + Y by dividing Equation 2 by Equation 1
        val2 = val2 / val1; 
        
        // Now we have:
        // X - Y = val1
        // X + Y = val2
        // X = (val1 + val2) / 2
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }

    // 4. OPTIMAL 2: The Bitwise XOR Method
    // Time Complexity: O(N) | Space Complexity: O(1)
    vector<int> findMissingRepeatingXOR(vector<int>& arr) {
        int n = arr.size();
        int xr = 0;
        
        // Step 1: XOR all array elements AND all numbers from 1 to N
        for (int i = 0; i < n; i++) {
            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }
        
        // xr now holds (Repeating ^ Missing).
        // Step 2: Find the rightmost set bit in xr to differentiate the two numbers
        int bitNo = 0;
        while (true) {
            if ((xr & (1 << bitNo)) != 0) break;
            bitNo++;
        }
        
        // Step 3: Group numbers into two clubs based on that bit
        int zeroClub = 0;
        int oneClub = 0;
        
        for (int i = 0; i < n; i++) {
            // Check array elements
            if ((arr[i] & (1 << bitNo)) != 0) oneClub = oneClub ^ arr[i];
            else zeroClub = zeroClub ^ arr[i];
            
            // Check numbers from 1 to N
            if (((i + 1) & (1 << bitNo)) != 0) oneClub = oneClub ^ (i + 1);
            else zeroClub = zeroClub ^ (i + 1);
        }
        
        // Step 4: We have the two numbers, but don't know which is which. 
        // Do a quick pass to verify which one is actually in the array.
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == zeroClub) count++;
        }
        
        if (count == 2) return {zeroClub, oneClub};
        return {oneClub, zeroClub};
    }
};

int main() {
    Solution obj;
    vector<int> arr = {3, 1, 2, 5, 3}; 

    

    vector<int> r1 = obj.findMissingRepeatingBrute(arr);
    cout << "1. Brute (Nested Loops) : [Repeating: " << r1[0] << ", Missing: " << r1[1] << "]\n";

    vector<int> r2 = obj.findMissingRepeatingBetter(arr);
    cout << "2. Better (Hash Array)  : [Repeating: " << r2[0] << ", Missing: " << r2[1] << "]\n";

    vector<int> r3 = obj.findMissingRepeatingMath(arr);
    cout << "3. Optimal 1 (Math)     : [Repeating: " << r3[0] << ", Missing: " << r3[1] << "]\n";

    vector<int> r4 = obj.findMissingRepeatingXOR(arr);
    cout << "4. Optimal 2 (XOR)      : [Repeating: " << r4[0] << ", Missing: " << r4[1] << "]\n";

    return 0;
}