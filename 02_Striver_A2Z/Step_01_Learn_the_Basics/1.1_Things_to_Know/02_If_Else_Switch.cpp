#include <iostream>
using namespace std;

class Solution {
public:
    // If-Else Logic
    string checkAge(int age) {
        if (age < 18) return "Minor";
        else if (age >= 18 && age < 60) return "Adult";
        else return "Senior";
    }

    // Switch Logic
    string getDay(int dayNum) {
        switch(dayNum) {
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
            case 7: return "Sunday";
            default: return "Invalid Day";
        }
    }
};

int main() {
    Solution obj;
    cout << "Age 20 is: " << obj.checkAge(20) << endl;
    cout << "Day 3 is: " << obj.getDay(3) << endl;
    return 0;
}