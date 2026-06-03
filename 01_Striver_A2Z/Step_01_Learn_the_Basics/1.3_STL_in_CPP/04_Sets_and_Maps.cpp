#include <iostream>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    void explainSet() {
        set<int> st;
        st.insert(1);
        st.insert(2);
        st.insert(2); // Ignored, sets only store unique values
        
        cout << "Set contains: ";
        for(auto it : st) cout << it << " "; // Prints 1 2
        cout << endl;
    }

    void explainMap() {
        map<int, string> mpp;
        mpp[1] = "Ashish";
        mpp[2] = "C++";
        
        cout << "Map elements: " << endl;
        for(auto it : mpp) {
            cout << it.first << " -> " << it.second << endl;
        }
    }
};

int main() {
    Solution obj;
    cout << "--- Sets ---" << endl;
    obj.explainSet();
    cout << "\n--- Maps ---" << endl;
    obj.explainMap();
    return 0;
}