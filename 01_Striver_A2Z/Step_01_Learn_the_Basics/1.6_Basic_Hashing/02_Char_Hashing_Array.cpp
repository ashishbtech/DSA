#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Hashing lowercase alphabets
    vector<int> countCharFrequency(const string& s) {
        vector<int> hashArr(26, 0);
        
        for (char ch : s) {
            hashArr[ch - 'a']++;
        }
        return hashArr;
    }
};

int main() {
    Solution obj;
    string s = "abcdabeaz";
    
    vector<int> hashArr = obj.countCharFrequency(s);
    
    // Simulating queries
    cout << "Frequency of 'a': " << hashArr['a' - 'a'] << endl;
    cout << "Frequency of 'b': " << hashArr['b' - 'a'] << endl;
    cout << "Frequency of 'z': " << hashArr['z' - 'a'] << endl;
    
    return 0;
}