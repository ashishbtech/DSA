#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Sort the array repeatedly
    // Time Complexity: O(N^2 log N) | Space Complexity: O(1) auxiliary
    long long minCostBrute(vector<long long> &arr)
    {
        long long totalCost = 0;
        int n = arr.size();

        // Loop until only 1 rope is left
        while (arr.size() > 1)
        {
            // Sort to bring the two smallest ropes to the front
            sort(arr.begin(), arr.end());

            // Connect the two smallest ropes
            long long currentCost = arr[0] + arr[1];
            totalCost += currentCost;

            // Remove the two small ropes and insert the combined rope
            arr.erase(arr.begin());
            arr.erase(arr.begin());
            arr.push_back(currentCost);
        }

        return totalCost;
    }

    // OPTIMAL: Use a Min Heap to continually extract the two smallest ropes
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    long long minCostOptimal(vector<long long> &arr)
    {
        
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());

        long long totalCost = 0;

        // Continue until only one single connected rope remains
        while (minHeap.size() > 1)
        {
            // Extract the two smallest ropes
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();

            // The cost to connect them
            long long currentCost = first + second;
            totalCost += currentCost;

            // Throw the newly connected rope back into the pile
            minHeap.push(currentCost);
        }

        return totalCost;
    }
};

int main()
{
    Solution obj;

    vector<long long> arr1 = {4, 3, 2, 6};
    cout << "Ropes: [4, 3, 2, 6]\n";

    
    vector<long long> arr1_copy = arr1;
    cout << "Brute Force: " << obj.minCostBrute(arr1_copy) << "\n";
    cout << "Optimal:     " << obj.minCostOptimal(arr1) << "\n";
    
    cout << "---\n";

    vector<long long> arr2 = {1, 2, 3};
    cout << "Ropes: [1, 2, 3]\n";
    cout << "Optimal:     " << obj.minCostOptimal(arr2) << "\n";
   
    return 0;
}