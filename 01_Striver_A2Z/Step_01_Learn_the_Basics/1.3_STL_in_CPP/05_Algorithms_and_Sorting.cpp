#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void explainAlgorithms() {
        vector<int> v = {4, 2, 5, 1, 3};
        
        // Sorting in Ascending Order
        sort(v.begin(), v.end());
        cout << "Sorted Ascending: ";
        for(auto it : v) cout << it << " ";
        cout << endl;

        // Sorting in Descending Order
        sort(v.begin(), v.end(), greater<int>());
        cout << "Sorted Descending: ";
        for(auto it : v) cout << it << " ";
        cout << endl;
        
        // Max and Min elements
        int maxi = *max_element(v.begin(), v.end());
        cout << "Max Element: " << maxi << endl;
    }
};

int main() {
    Solution obj;
    cout << "--- STL Algorithms ---" << endl;
    obj.explainAlgorithms();
    return 0;
}