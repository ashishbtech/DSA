//Take a character and check if it’s a vowel or consonant

#include <iostream>
using namespace std;

class Solution {
public:
    string checkCharacter(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return "Vowel";
        else
            return "Consonant";
    }
};

int main() {
    Solution obj;

    char ch;
    cin >> ch;

    cout << obj.checkCharacter(ch);

    return 0;
}