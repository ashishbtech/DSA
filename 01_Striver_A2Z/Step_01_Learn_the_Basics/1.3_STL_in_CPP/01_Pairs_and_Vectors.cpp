#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    void explainPair() {
        pair<int, int> p = {1, 3};
        cout << "Pair: " << p.first << " " << p.second << endl;
        
        pair<int, pair<int, int>> nested = {1, {3, 4}};
        cout << "Nested Pair: " << nested.first << " " << nested.second.first << endl;
    }

    void explainVector() {
        vector<int> v;
        v.push_back(1);
        v.emplace_back(2); // Faster than push_back

        // Vector of pairs
        vector<pair<int, int>> vec;
        vec.push_back({1, 2});
        vec.emplace_back(1, 2); 

        // Pre-filled vector: size 5, all elements initialized to 100
        vector<int> v2(5, 100); 

        cout << "Vector v2 elements: ";
        for(auto it : v2) {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution obj;
    cout << "--- Pairs ---" << endl;
    obj.explainPair();
    cout << "\n--- Vectors ---" << endl;
    obj.explainVector();
    return 0;
}