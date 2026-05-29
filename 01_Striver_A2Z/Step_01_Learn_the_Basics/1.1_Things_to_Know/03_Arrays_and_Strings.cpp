#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void manipulateString(string s) {
        cout << "Original String: " << s << endl;
        s[5] = 'q'; // Strings are mutable in C++
        cout << "Modified String: " << s << endl;
        cout << "Length: " << s.length() << endl;
    }

    void displayArray(int arr[], int size) {
        cout << "Array elements: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution obj;
    
    string name = "Ashish";
    obj.manipulateString(name);
    
    int myArr[5] = {10, 20, 30, 40, 50};
    obj.displayArray(myArr, 5);

    return 0;
}