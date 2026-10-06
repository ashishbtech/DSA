#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BETTER: Using a TreeMap to keep keys sorted
    // Time Complexity: O(N log M) | Space Complexity: O(M)
    bool isNStraightHandMap(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mpp;
        for (int card : hand)
        {
            mpp[card]++;
        }

        for (auto it : mpp)
        {
            int startCard = it.first;
            int count = it.second;

            // If this card still needs to be grouped
            if (count > 0)
            {
                // Try to form 'count' number of straights
                for (int i = 0; i < groupSize; i++)
                {
                    if (mpp[startCard + i] < count)
                    {
                        return false; // Not enough consecutive cards
                    }
                    mpp[startCard + i] -= count;
                }
            }
        }
        return true;
    }

    // OPTIMAL HEAP APPROACH: Min Heap + Unordered Map
    // Time Complexity: O(N log M) | Space Complexity: O(M)
    bool isNStraightHandOptimal(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> counts;
        for (int card : hand)
        {
            counts[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto it : counts)
        {
            minHeap.push(it.first);
        }

        while (!minHeap.empty())
        {
            int startCard = minHeap.top();

            // If this card's frequency is already 0, it was used in previous straights
            if (counts[startCard] == 0)
            {
                minHeap.pop();
                continue;
            }

            // We must form a straight starting with startCard
            for (int i = 0; i < groupSize; i++)
            {
                int currentCard = startCard + i;

                // If a required consecutive card is missing
                if (counts[currentCard] == 0)
                {
                    return false;
                }

                counts[currentCard]--;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << "Hand: [1, 2, 3, 6, 2, 3, 4, 7, 8] | Group Size: 3\n";
    cout << "Map Approach:  " << (obj.isNStraightHandMap(hand1, groupSize1) ? "True" : "False") << "\n";
    cout << "Heap Approach: " << (obj.isNStraightHandOptimal(hand1, groupSize1) ? "True" : "False") << "\n";

    cout << "---\n";

    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;
    cout << "Hand: [1, 2, 3, 4, 5] | Group Size: 4\n";
    cout << "Heap Approach: " << (obj.isNStraightHandOptimal(hand2, groupSize2) ? "True" : "False") << "\n";

    cout << "---\n";

    vector<int> hand3 = {8, 10, 12};
    int groupSize3 = 3;
    cout << "Hand: [8, 10, 12] | Group Size: 3\n";
    cout << "Heap Approach: " << (obj.isNStraightHandOptimal(hand3, groupSize3) ? "True" : "False") << "\n";

    return 0;
}