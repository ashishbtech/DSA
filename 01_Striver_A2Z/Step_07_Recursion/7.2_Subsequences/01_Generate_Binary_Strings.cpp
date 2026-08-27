#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void generateHelper(int n, string current, vector<string> &result)
    {
        // Base Case: We've built a string of the target length
        if (current.length() == n)
        {
            result.push_back(current);
            return;
        }

        // Branch 1: We can ALWAYS safely append a '0'
        generateHelper(n, current + "0", result);

        // Branch 2: We can only append a '1' if it won't create consecutive 1s
        if (current.empty() || current.back() == '0')
        {
            generateHelper(n, current + "1", result);
        }
    }

public:
    // OPTIMAL: Recursive Tree Pruning
    // Time Complexity: O(2^N) strictly bounded by valid answers | Space Complexity: O(N) for Call Stack
    vector<string> generateBinaryStrings(int n)
    {
        vector<string> result;
        generateHelper(n, "", result);
        return result;
    }
};

int main()
{
    Solution obj;

    int n1 = 3;
    vector<string> res1 = obj.generateBinaryStrings(n1);

    cout << "N = " << n1 << " -> Valid Strings: [ ";
    for (const string &s : res1)
    {
        cout << s << " ";
    }
    cout << "]\n\n";

    int n2 = 4;
    vector<string> res2 = obj.generateBinaryStrings(n2);

    cout << "N = " << n2 << " -> Valid Strings: [ ";
    for (const string &s : res2)
    {
        cout << s << " ";
    }
    cout << "]\n";

    return 0;
}