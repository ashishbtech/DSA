#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Greedy Monotonic Stack
    // Time Complexity: O(N) | Space Complexity: O(N) auxiliary string
    string removeKdigits(string num, int k)
    {
        string ans = ""; // Acts as our monotonic increasing stack

        for (int i = 0; i < num.length(); i++)
        {
            char current = num[i];

            // Pop from stack if current digit is smaller and we still have k removals left
            while (ans.length() > 0 && ans.back() > current && k > 0)
            {
                ans.pop_back();
                k--;
            }

            // Push to stack, but prevent leading zeros
            if (ans.length() > 0 || current != '0')
            {
                ans.push_back(current);
            }
        }

        // If we still have k removals left (e.g., digits were in increasing order)
        while (ans.length() > 0 && k > 0)
        {
            ans.pop_back();
            k--;
        }

        // If the string is completely empty after all removals
        if (ans == "")
        {
            return "0";
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string num1 = "1432219";
    int k1 = 3;
    cout << obj.removeKdigits(num1, k1) << "\n";

    string num2 = "10200";
    int k2 = 1;
    cout << obj.removeKdigits(num2, k2) << "\n";

    string num3 = "10";
    int k3 = 2;
    cout << obj.removeKdigits(num3, k3) << "\n";

    return 0;
}