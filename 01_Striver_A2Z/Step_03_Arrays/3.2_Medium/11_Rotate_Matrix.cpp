#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. BRUTE FORCE: Use a secondary dummy matrix to place elements
    // The element at [i][j] moves to [j][n - 1 - i]
    // Time Complexity: O(N^2) | Space Complexity: O(N^2)
    void rotateBrute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dummy(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dummy[j][n - 1 - i] = matrix[i][j];
            }
        }
        
        // Copy back to original array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = dummy[i][j];
            }
        }
    }

    // 2. OPTIMAL: In-place Transpose -> Reverse
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    void rotateOptimal(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix (swap [i][j] with [j][i])
        // Notice j loops strictly up to 'i' to avoid double-swapping back to original
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse every row horizontally
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution obj;
    vector<vector<int>> raw = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    

    vector<vector<int>> mBrute = raw;
    obj.rotateBrute(mBrute);
    cout << "Brute Output (O(N^2) Space):\n";
    for(auto& row : mBrute) {
        for(int val : row) cout << val << " ";
        cout << "\n";
    }

    vector<vector<int>> mOptimal = raw;
    obj.rotateOptimal(mOptimal);
    cout << "\nOptimal Output (O(1) Space):\n";
    for(auto& row : mOptimal) {
        for(int val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}