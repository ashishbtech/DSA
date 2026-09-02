#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int index, string path, long long currentSum, long long prevVal, string &num, int target, vector<string> &ans)
    {
        // Base case: We reached the end of the string
        if (index == num.length())
        {
            if (currentSum == target)
            {
                ans.push_back(path);
            }
            return;
        }

        string currentStr = "";
        long long currentVal = 0;

        // Loop to partition the string and form the next operand
        for (int i = index; i < num.length(); i++)
        {

            // Trap: Prevent leading zeros in operands (e.g., "05" is invalid, but "0" is fine)
            if (i > index && num[index] == '0')
                break;

            currentStr += num[i];
            currentVal = currentVal * 10 + (num[i] - '0');

            if (index == 0)
            {
                // The very first number of the expression shouldn't have an operator before it
                solve(i + 1, path + currentStr, currentVal, currentVal, num, target, ans);
            }
            else
            {
                // Branch 1: Addition
                solve(i + 1, path + "+" + currentStr, currentSum + currentVal, currentVal, num, target, ans);

                // Branch 2: Subtraction
                solve(i + 1, path + "-" + currentStr, currentSum - currentVal, -currentVal, num, target, ans);

                // Branch 3: Multiplication (Undo previous operation mathematically)
                solve(i + 1, path + "*" + currentStr, currentSum - prevVal + (prevVal * currentVal), prevVal * currentVal, num, target, ans);
            }
        }
    }

public:
    // OPTIMAL: DFS Backtracking with mathematical state reversion
    // Time Complexity: O(4^N) | Space Complexity: O(N) for Call Stack
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        solve(0, "", 0, 0, num, target, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    string num = "123";
    int target = 6;

    vector<string> ans = obj.addOperators(num, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}