#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 1. BRUTE FORCE: Generate all subarrays using 3 loops and check their sum
    // Time Complexity: O(N^3) | Space Complexity: O(1)
    int subarraySumBrute(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int l = i; l <= j; l++) {
                    sum += arr[l];
                }
                if (sum == k) count++;
            }
        }
        return count;
    }

    // 2. BETTER: Optimize the 3rd loop by keeping a running sum for the inner loop
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int subarraySumBetter(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) count++;
            }
        }
        return count;
    }

    // 3. OPTIMAL: Prefix Sum with Hash Map
    // Logic: If (currentSum - k) exists in the map, a valid subarray sits between that old point and here.
    // Time Complexity: O(N) | Space Complexity: O(N)
    int subarraySumOptimal(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1; // Base case: an initial sum of 0 has occurred 1 time
        
        int preSum = 0, count = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            preSum += arr[i];
            int remove = preSum - k;
            
            // If the chunk we need to remove to get 'k' exists, add its frequency to our count
            if (mpp.find(remove) != mpp.end()) {
                count += mpp[remove];
            }
            
            // Log the current prefix sum into the map for future numbers to look back at
            mpp[preSum] += 1;
        }
        return count;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;

    cout << "1. Brute Force : " << obj.subarraySumBrute(arr, k) << " subarrays (O(N^3))\n";
    cout << "2. Better      : " << obj.subarraySumBetter(arr, k) << " subarrays (O(N^2))\n";
    cout << "3. Optimal     : " << obj.subarraySumOptimal(arr, k) << " subarrays (O(N))\n";

    return 0;
}