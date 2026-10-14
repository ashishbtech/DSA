#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Greedy simulation
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool lemonadeChange(vector<int> &bills)
    {
        int count5 = 0;
        int count10 = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                count5++;
            }
            else if (bill == 10)
            {
                if (count5 > 0)
                {
                    count5--;
                    count10++;
                }
                else
                {

                    return false;
                }
            }
            else
            {
                if (count10 > 0 && count5 > 0)
                {
                    count10--;
                    count5--;
                }

                else if (count5 >= 3)
                {
                    count5 -= 3;
                }

                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

void printResult(bool result)
{
    cout << (result ? "True (Can serve all customers)" : "False (Cannot make change)") << "\n";
}

int main()
{
    Solution obj;

    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Bills: [5, 5, 5, 10, 20]\n";
    cout << "Result: ";
    printResult(obj.lemonadeChange(bills1));

    cout << "---\n";

    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << "Bills: [5, 5, 10, 10, 20]\n";
    cout << "Result: ";
    printResult(obj.lemonadeChange(bills2));

    cout << "---\n";

    vector<int> bills3 = {5, 5, 5, 5, 20, 20, 5, 5, 20, 5};
    cout << "Bills: [5, 5, 5, 5, 20, 20, 5, 5, 20, 5]\n";
    cout << "Result: ";
    printResult(obj.lemonadeChange(bills3));

    return 0;
}