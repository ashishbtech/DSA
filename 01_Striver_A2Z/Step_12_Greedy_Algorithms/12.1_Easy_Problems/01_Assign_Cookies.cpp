#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Greedy + Two Pointers
    // Time Complexity: O(N log N + M log M) | Space Complexity: O(1)
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        while (i < g.size() && j < s.size())
        {

            if (s[j] >= g[i])
            {
                i = i + 1;
            }

            j = j + 1;
        }

        return i;
    }
};

int main()
{
    Solution obj;

    vector<int> greed1 = {1, 2, 3};
    vector<int> cookies1 = {1, 1};
    cout << "Greed: [1, 2, 3] | Cookies: [1, 1]\n";
    cout << "Content Children: " << obj.findContentChildren(greed1, cookies1) << "\n";

    cout << "---\n";

    vector<int> greed2 = {1, 2};
    vector<int> cookies2 = {1, 2, 3};
    cout << "Greed: [1, 2] | Cookies: [1, 2, 3]\n";
    cout << "Content Children: " << obj.findContentChildren(greed2, cookies2) << "\n";

    cout << "---\n";

    vector<int> greed3 = {10, 9, 8, 7};
    vector<int> cookies3 = {5, 6, 7, 8};
    cout << "Greed: [10, 9, 8, 7] | Cookies: [5, 6, 7, 8]\n";
    cout << "Content Children: " << obj.findContentChildren(greed3, cookies3) << "\n";

    return 0;
}