#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. BRUTE FORCE: Dump everything into a 3rd array, sort, and distribute back
    // Time Complexity: O((N+M) + (N+M)log(N+M)) | Space Complexity: O(N+M)
    void mergeBrute(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        vector<int> temp(n + m);
        int k = 0;
        
        for (int i = 0; i < n; i++) temp[k++] = arr1[i];
        for (int i = 0; i < m; i++) temp[k++] = arr2[i];
        
        sort(temp.begin(), temp.end());
        
        k = 0;
        for (int i = 0; i < n; i++) arr1[i] = temp[k++];
        for (int i = 0; i < m; i++) arr2[i] = temp[k++];
    }

    // 2. OPTIMAL 1: Two Pointers (Swap and Sort)
    // Time Complexity: O(min(N, M)) + O(N log N) + O(M log M) | Space Complexity: O(1)
    void mergeOptimal1(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        int left = n - 1; // Tail of arr1
        int right = 0;    // Head of arr2

        // Swap the largest items from arr1 with the smallest from arr2
        while (left >= 0 && right < m) {
            if (arr1[left] > arr2[right]) {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            } else {
                break; // Because they are sorted, if one fails, all subsequent will fail
            }
        }

        // Re-align internal ordering
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
    }

    // 3. OPTIMAL 2 (HARDCORE): The Gap Method (Derived from Shell Sort)
    // Time Complexity: O((N+M) log(N+M)) | Space Complexity: O(1)
    void mergeGapMethod(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int len = n + m;
        int gap = (len / 2) + (len % 2); // math trick for ceiling division

        // Lambda helper to handle index math across two disjoint arrays
        auto swapIfGreater = [&](int idx1, int idx2) {
            // Both pointers inside arr1
            if (idx1 < n && idx2 < n) {
                if (arr1[idx1] > arr1[idx2]) swap(arr1[idx1], arr1[idx2]);
            }
            // Pointer 1 in arr1, Pointer 2 in arr2
            else if (idx1 < n && idx2 >= n) {
                if (arr1[idx1] > arr2[idx2 - n]) swap(arr1[idx1], arr2[idx2 - n]);
            }
            // Both pointers inside arr2
            else if (idx1 >= n && idx2 >= n) {
                if (arr2[idx1 - n] > arr2[idx2 - n]) swap(arr2[idx1 - n], arr2[idx2 - n]);
            }
        };

        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            
            while (right < len) {
                swapIfGreater(left, right);
                left++;
                right++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};

int main() {
    Solution obj;
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

  

    vector<int> t2_a = arr1, t2_b = arr2;
    obj.mergeOptimal1(t2_a, t2_b);
    cout << "Optimal 1 (Swap & Sort) :\nArr1: ";
    for(int x: t2_a) cout << x << " ";
    cout << "\nArr2: ";
    for(int x: t2_b) cout << x << " ";
    cout << "\n\n";

    vector<int> t3_a = arr1, t3_b = arr2;
    obj.mergeGapMethod(t3_a, t3_b);
    cout << "Optimal 2 (Gap Method)  :\nArr1: ";
    for(int x: t3_a) cout << x << " ";
    cout << "\nArr2: ";
    for(int x: t3_b) cout << x << " ";
    cout << "\n";

    return 0;
}