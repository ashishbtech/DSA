#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores value and weight
struct Item
{
    int value;
    int weight;
};

class Solution
{
private:
    // Custom comparator to sort items by value/weight ratio descending
    static bool comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

public:
    // OPTIMAL: Greedy Sorting by Ratio
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Step 1: Sort items in descending order of value/weight ratio
        sort(arr, arr + n, comp);

        int currentWeight = 0;
        double finalValue = 0.0;

        // Step 2: Iterate through sorted items
        for (int i = 0; i < n; i++)
        {
            // If the whole item fits, take it
            if (currentWeight + arr[i].weight <= W)
            {
                currentWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            // If only a fraction fits, take the remaining capacity and break
            else
            {
                int remain = W - currentWeight;
                finalValue += ((double)arr[i].value / (double)arr[i].weight) * (double)remain;
                break; // Knapsack is full
            }
        }

        return finalValue;
    }
};

int main()
{
    Solution obj;

    int W1 = 50;
    Item arr1[] = {{60, 10}, {100, 20}, {120, 30}};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Capacity: 50 | Items: [{v:60, w:10}, {v:100, w:20}, {v:120, w:30}]\n";
    cout << "Maximum Value: " << obj.fractionalKnapsack(W1, arr1, n1) << "\n";

    cout << "---\n";

    int W2 = 50;
    Item arr2[] = {{10, 10}, {20, 20}, {30, 30}};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Capacity: 50 | Items: [{v:10, w:10}, {v:20, w:20}, {v:30, w:30}]\n";
    cout << "Maximum Value: " << obj.fractionalKnapsack(W2, arr2, n2) << "\n";

    return 0;
}