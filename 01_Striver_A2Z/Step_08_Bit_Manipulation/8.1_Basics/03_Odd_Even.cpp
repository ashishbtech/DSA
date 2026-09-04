#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: CPU-level bitwise check
    // Time Complexity: O(1) | Space Complexity: O(1)
    string oddEven(int n)
    {

        if ((n & 1) == 1)
        {
            return "odd";
        }
        else
        {
            return "even";
        }
    }
};

int main()
{
    Solution obj;
    int n1 = 5;
    int n2 = 14;

    cout << n1 << " is " << obj.oddEven(n1) << "\n";
    cout << n2 << " is " << obj.oddEven(n2) << "\n";

    return 0;
}