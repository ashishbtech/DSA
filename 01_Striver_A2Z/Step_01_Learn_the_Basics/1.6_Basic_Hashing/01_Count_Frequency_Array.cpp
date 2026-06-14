#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Pre-allocating a hash array up to maxVal
    vector<int> countFrequency(const vector<int>& arr, int maxVal) {
        vector<int> hashArr(maxVal + 1, 0);
        
        for (int num : arr) {
            if (num <= maxVal) {
                hashArr[num]++;
            }
        }
        return hashArr;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 3, 2, 1, 3, 4, 1};
    int maxVal = 4; // Max element we expect to hash
    
    vector<int> hashArr = obj.countFrequency(arr, maxVal);
    
    // Simulating queries
    cout << "Frequency of 1: " << hashArr[1] << endl;
    cout << "Frequency of 3: " << hashArr[3] << endl;
    
    return 0;
}