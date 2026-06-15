#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element
            swap(arr[minIndex], arr[i]);
        }
    }
};

int main() {
    Solution obj;
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    
    obj.selectionSort(arr);
    
    cout << "Selection Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}