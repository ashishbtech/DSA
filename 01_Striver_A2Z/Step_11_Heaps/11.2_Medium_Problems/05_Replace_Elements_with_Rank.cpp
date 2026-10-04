#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: For every element, count unique strictly smaller elements
    // Time Complexity: O(N^2 log N) | Space Complexity: O(N)
    vector<int> arrayRankTransformBrute(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            set<int> uniqueSmaller;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] < arr[i])
                {
                    uniqueSmaller.insert(arr[j]);
                }
            }

            res[i] = uniqueSmaller.size() + 1;
        }
        return res;
    }

    // OPTIMAL: Min Heap and Hash Map
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    vector<int> arrayRankTransformOptimal(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

        unordered_map<int, int> rankMap;
        int rank = 1;

        while (!minHeap.empty())
        {
            int current = minHeap.top();
            minHeap.pop();

            if (rankMap.find(current) == rankMap.end())
            {
                rankMap[current] = rank++;
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = rankMap[arr[i]];
        }

        return res;
    }
};

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    Solution obj;

    vector<int> arr1 = {40, 10, 20, 30};
    cout << "Array: [40, 10, 20, 30]\n";
    cout << "Brute Force: ";
    printArray(obj.arrayRankTransformBrute(arr1));
    cout << "Optimal:     ";
    printArray(obj.arrayRankTransformOptimal(arr1));

    cout << "---\n";

    vector<int> arr2 = {100, 100, 100};
    cout << "Array: [100, 100, 100]\n";
    cout << "Optimal:     ";
    printArray(obj.arrayRankTransformOptimal(arr2));

    cout << "---\n";

    vector<int> arr3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    cout << "Array: [37, 12, 28, 9, 100, 56, 80, 5, 12]\n";
    cout << "Optimal:     ";
    printArray(obj.arrayRankTransformOptimal(arr3));

    return 0;
}