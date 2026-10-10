#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BRUTE FORCE: Generate all N*N combinations and sort
    // Time Complexity: O(N^2 log(N^2)) | Space Complexity: O(N^2)
    vector<int> maxCombinationsBrute(vector<int>& A, vector<int>& B, int C) {
        vector<int> allSums;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                allSums.push_back(A[i] + B[j]);
            }
        }
        
        // Sort in descending order
        sort(allSums.begin(), allSums.end(), greater<int>());
        
        // Take the top C elements
        vector<int> result(allSums.begin(), allSums.begin() + C);
        return result;
    }

    // OPTIMAL: Sort + Max Heap + Set
    // Time Complexity: O(N log N + C log N) | Space Complexity: O(C)
    vector<int> maxCombinationsOptimal(vector<int>& A, vector<int>& B, int C) {
        // Sort both arrays in descending order to maximize sums early
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        // Max Heap storing pair<sum, pair<indexA, indexB>>
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        
        // Set to track visited index pairs to avoid duplicates
        set<pair<int, int>> visited;
        
        // Push the absolute maximum sum
        maxHeap.push({A[0] + B[0], {0, 0}});
        visited.insert({0, 0});
        
        vector<int> result;
        
        // Extract C times
        for (int count = 0; count < C; count++) {
            auto current = maxHeap.top();
            maxHeap.pop();
            
            result.push_back(current.first);
            int i = current.second.first;
            int j = current.second.second;
            
            // Push candidate 1: move down in array A
            if (i + 1 < A.size() && visited.find({i + 1, j}) == visited.end()) {
                maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
            // Push candidate 2: move down in array B
            if (j + 1 < B.size() && visited.find({i, j + 1}) == visited.end()) {
                maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        
        return result;
    }
};

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    Solution obj;
    
    vector<int> A1 = {3, 2};
    vector<int> B1 = {1, 4};
    int C1 = 2;
    cout << "A: [3, 2] | B: [1, 4] | C: 2\n";
    cout << "Brute Force: ";
    printArray(obj.maxCombinationsBrute(A1, B1, C1));
    cout << "Optimal:     ";
    printArray(obj.maxCombinationsOptimal(A1, B1, C1));
    
    cout << "---\n";
    
    vector<int> A2 = {1, 4, 2, 3};
    vector<int> B2 = {2, 5, 1, 6};
    int C2 = 4;
    cout << "A: [1, 4, 2, 3] | B: [2, 5, 1, 6] | C: 4\n";
    cout << "Optimal:     ";
    printArray(obj.maxCombinationsOptimal(A2, B2, C2));
   
    
    return 0;
}