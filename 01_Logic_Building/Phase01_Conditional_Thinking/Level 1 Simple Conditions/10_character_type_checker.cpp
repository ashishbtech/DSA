//Take a character and check whether it’s uppercase, lowercase, a digit, or a special character

#include <iostream>
using namespace std;

class Solution {
public:
    string checkCharacter(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return "Uppercase";
        else if (ch >= 'a' && ch <= 'z')
            return "Lowercase";
        else if (ch >= '0' && ch <= '9')
            return "Digit";
        else
            return "Special Character";
    }
};

int main() {
    Solution obj;

    char ch;
    cin >> ch;

    cout << obj.checkCharacter(ch);

    return 0;
}