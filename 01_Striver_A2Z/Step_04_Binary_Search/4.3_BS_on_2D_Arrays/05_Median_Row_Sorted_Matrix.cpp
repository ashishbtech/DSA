#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    int countSmallerThanOrEqual(vector<vector<int>>& matrix, int r, int c, int x) {
        int count = 0;
        for (int i = 0; i < r; i++) {
            
            count += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
        }
        return count;
    }

public:
    // 1. BRUTE FORCE: Flatten, Sort, and pick the middle element
    // Time Complexity: O(R*C log(R*C)) | Space Complexity: O(R*C)
    int medianBrute(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> flattened;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                flattened.push_back(matrix[i][j]);
            }
        }
        
        sort(flattened.begin(), flattened.end());
        return flattened[(r * c) / 2];
    }

    // 2. OPTIMAL: Binary Search on Value Range + Row-wise Upper Bound
    // Time Complexity: O(log(Max - Min) * R * log C) | Space Complexity: O(1)
    int medianOptimal(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < r; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][c - 1]);
        }
        
        int required = (r * c) / 2;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countSmallerThanOrEqual(matrix, r, c, mid);
            
            if (count <= required) {
               
                low = mid + 1;
            } else {
               
                high = mid - 1;
            }
        }
        
        
        return low;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {
        {1, 3, 8},
        {2, 3, 4},
        {1, 2, 5}
    };
   

    cout << "Brute Force : " << obj.medianBrute(matrix) << "\n";
    cout << "Optimal     : " << obj.medianOptimal(matrix) << "\n";

    return 0;
}