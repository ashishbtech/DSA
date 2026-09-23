#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Generate all subarrays and use a set
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int totalFruitBrute(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            set<int> basket;
            for (int j = i; j < n; j++)
            {
                basket.insert(fruits[j]);

                if (basket.size() > 2)
                {
                    break;
                }

                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // OPTIMAL: Sliding Window with a frequency map
    // Time Complexity: O(N) | Space Complexity: O(1)
    int totalFruitOptimal(vector<int> &fruits)
    {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<int, int> mpp;

        while (right < n)
        {
            // Add the current fruit to the basket map
            mpp[fruits[right]]++;

            // If window becomes invalid (> 2 types), shrink from the left
            while (mpp.size() > 2)
            {
                mpp[fruits[left]]--;

                // If a fruit count hits 0, it is completely out of the basket
                if (mpp[fruits[left]] == 0)
                {
                    mpp.erase(fruits[left]);
                }
                left++;
            }

            // Window is valid, update max length
            maxLen = max(maxLen, right - left + 1);

            // Expand to the next tree
            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    vector<int> fruits1 = {1, 2, 1};
    cout << "Brute Force: " << obj.totalFruitBrute(fruits1) << "\n";
    cout << "Optimal: " << obj.totalFruitOptimal(fruits1) << "\n";

    cout << "---\n";

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Optimal: " << obj.totalFruitOptimal(fruits2) << "\n";

    cout << "---\n";

    vector<int> fruits3 = {1, 2, 3, 2, 2, 1, 4};
    cout << "Optimal: " << obj.totalFruitOptimal(fruits3) << "\n";

    return 0;
}