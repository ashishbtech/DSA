#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: Stack-based Simulation
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++)
        {
            int current = asteroids[i];
            bool currentDestroyed = false;

            while (!st.empty() && st.back() > 0 && current < 0)
            {

                if (st.back() < abs(current))
                {
                    st.pop_back();
                    continue;
                }

                else if (st.back() == abs(current))
                {
                    st.pop_back();
                    currentDestroyed = true;
                    break;
                }

                else
                {
                    currentDestroyed = true;
                    break;
                }
            }

            if (!currentDestroyed)
            {
                st.push_back(current);
            }
        }

        return st;
    }
};

int main()
{
    Solution obj;

    vector<int> ast1 = {5, 10, -5};
    vector<int> ans1 = obj.asteroidCollision(ast1);
    for (int x : ans1)
        cout << x << " ";
    cout << "\n"; // Expected: 5 10

    vector<int> ast2 = {8, -8};
    vector<int> ans2 = obj.asteroidCollision(ast2);
    for (int x : ans2)
        cout << x << " ";
    cout << "\n"; // Expected: (empty)

    vector<int> ast3 = {10, 2, -5};
    vector<int> ans3 = obj.asteroidCollision(ast3);
    for (int x : ans3)
        cout << x << " ";
    cout << "\n"; // Expected: 10

    vector<int> ast4 = {-2, -1, 1, 2};
    vector<int> ans4 = obj.asteroidCollision(ast4);
    for (int x : ans4)
        cout << x << " ";
    cout << "\n"; // Expected: -2 -1 1 2 (They never meet)

    return 0;
}