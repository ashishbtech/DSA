#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Hash Map + Sorting
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    vector<int> topKFrequentBrute(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // Transfer to a vector of pairs {frequency, number}
        vector<pair<int, int>> freqVec;
        for (auto &it : freqMap)
        {
            freqVec.push_back({it.second, it.first});
        }

        // Sort in descending order based on frequency
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, int>>());

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(freqVec[i].second);
        }
        return res;
    }

    // OPTIMAL: Hash Map + Min Heap of size K
    // Time Complexity: O(N log K) | Space Complexity: O(N)
    vector<int> topKFrequentOptimal(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;
        // 1. Count the frequencies
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // 2. Min Heap storing pairs of {frequency, number}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto &it : freqMap)
        {
            minHeap.push({it.second, it.first});

            // If heap exceeds capacity K, kick out the smallest frequency
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        // 3. Extract the top K elements
        vector<int> res;
        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // The heap gives us the kth most frequent first, so reverse it
        // if you want them strictly from most frequent to least frequent
        reverse(res.begin(), res.end());

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

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    cout << "Array: [1, 1, 1, 2, 2, 3] | K = 2\n";
    cout << "Brute Force: ";
    printArray(obj.topKFrequentBrute(nums1, k1));
    cout << "Optimal:     ";
    printArray(obj.topKFrequentOptimal(nums1, k1));

    cout << "---\n";

    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "Array: [1] | K = 1\n";
    cout << "Optimal:     ";
    printArray(obj.topKFrequentOptimal(nums2, k2));

    cout << "---\n";

    vector<int> nums3 = {4, 4, 4, 4, 5, 5, 5, 6, 6, 7};
    int k3 = 3;
    cout << "Array: [4, 4, 4, 4, 5, 5, 5, 6, 6, 7] | K = 3\n";
    cout << "Optimal:     ";
    printArray(obj.topKFrequentOptimal(nums3, k3));

    return 0;
}