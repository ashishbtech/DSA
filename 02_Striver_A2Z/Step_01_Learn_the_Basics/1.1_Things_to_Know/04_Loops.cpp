#include <iostream>
using namespace std;

class Solution {
public:
    int sumUsingFor(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }

    int sumUsingWhile(int n) {
        int sum = 0;
        int i = 1;
        while (i <= n) {
            sum += i;
            i++;
        }
        return sum;
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "Sum to " << n << " (For Loop): " << obj.sumUsingFor(n) << endl;
    cout << "Sum to " << n << " (While Loop): " << obj.sumUsingWhile(n) << endl;
    return 0;
}