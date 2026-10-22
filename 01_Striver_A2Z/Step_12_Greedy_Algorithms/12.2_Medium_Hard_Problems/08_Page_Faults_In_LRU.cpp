#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL GREEDY APPROACH: Hash Set + Map for Timestamps
    // Time Complexity: O(N * C) | Space Complexity: O(C)
    int pageFaults(int c, vector<int> &pages)
    {
        unordered_set<int> memory;
        unordered_map<int, int> recentMap;
        int faults = 0;
        int n = pages.size();

        for (int i = 0; i < n; i++)
        {

            if (memory.find(pages[i]) == memory.end())
            {
                faults++;

                if (memory.size() == c)
                {
                    int lruPage = -1;
                    int minIndex = INT_MAX;

                    for (int page : memory)
                    {
                        if (recentMap[page] < minIndex)
                        {
                            minIndex = recentMap[page];
                            lruPage = page;
                        }
                    }

                    memory.erase(lruPage);
                }

                memory.insert(pages[i]);
            }

            recentMap[pages[i]] = i;
        }

        return faults;
    }
};

int main()
{
    Solution obj;

    vector<int> pages1 = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    int c1 = 4;

    cout << obj.pageFaults(c1, pages1) << "\n";

    vector<int> pages2 = {3, 1, 0, 2, 5, 4, 1, 2};
    int c2 = 4;

    cout << obj.pageFaults(c2, pages2) << "\n";

    return 0;
}