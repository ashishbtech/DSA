//Check if a given year is a leap year

#include <iostream>
using namespace std;

class Solution {
public:
    string checkLeapYear(int year) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return "Leap Year";
        else
            return "Not a Leap Year";
    }
};

int main() {
    Solution obj;

    int year;
    cin >> year;

    cout << obj.checkLeapYear(year);

    return 0;
}