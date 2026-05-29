//Take a temperature value and print “Cold”, “Warm”, or “Hot”

#include <iostream>
using namespace std;

class Solution {
public:
    string checkTemperature(int temp) {
        if (temp < 20)
            return "Cold";
        else if (temp <= 35)
            return "Warm";
        else
            return "Hot";
    }
};

int main() {
    Solution obj;

    int temp;
    cin >> temp;

    cout << obj.checkTemperature(temp);

    return 0;
}