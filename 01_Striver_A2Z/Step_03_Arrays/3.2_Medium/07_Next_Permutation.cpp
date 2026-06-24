#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Generate all possible sorted permutations, find 'arr', pick the next one.
    // Time Complexity: O(N! * N) | Space Complexity: O(N! * N)
    void nextPermutationBrute(vector<int> &arr)
    {
        vector<vector<int>> perms;

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        // Generate all permutations
        do
        {
            perms.push_back(temp);
        } while (next_permutation(temp.begin(), temp.end()));

        // Find current permutation and return the next one
        for (int i = 0; i < perms.size(); i++)
        {
            if (perms[i] == arr)
            {
                if (i == perms.size() - 1)
                    arr = perms[0]; // Wrap around to first permutation
                else
                    arr = perms[i + 1]; // Next permutation
                return;
            }
        }
    }

    // 2. BETTER: The C++ STL One-Liner
    // Time Complexity: O(N) | Space Complexity: O(1)
    void nextPermutationBetter(vector<int> &arr)
    {
        next_permutation(arr.begin(), arr.end());
    }

    // 3. OPTIMAL: Narayan Pandita's 3-Step Algorithm
    // Time Complexity: O(3N) ≈ O(N) | Space Complexity: O(1)
    void nextPermutationOptimal(vector<int> &arr)
    {
        int n = arr.size();
        int ind = -1;

        // Step 1: Find the "break point" (the first dip when reading right-to-left)
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                ind = i;
                break;
            }
        }

        // If no dip exists, the array is strictly descending (e.g. [5, 4, 3, 2, 1]).
        // The next permutation is the absolute lowest possible order -> reverse it.
        if (ind == -1)
        {
            reverse(arr.begin(), arr.end());
            return;
        }

        // Step 2: Find the smallest element strictly greater than arr[ind] sitting to its right, and swap
        for (int i = n - 1; i > ind; i--)
        {
            if (arr[i] > arr[ind])
            {
                swap(arr[i], arr[ind]);
                break;
            }
        }

        // Step 3: Reverse the remaining right-hand tail to flatten it into the lowest possible sequence
        reverse(arr.begin() + ind + 1, arr.end());
    }
};

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Solution obj;

    vector<int> arr = {2, 1, 5, 4, 3};

    cout << "Original Array: ";
    printArray(arr);

    vector<int> brute = arr;
    obj.nextPermutationBrute(brute);
    cout << "Brute Force: ";
    printArray(brute);

    vector<int> better = arr;
    obj.nextPermutationBetter(better);
    cout << "STL Approach: ";
    printArray(better);

    vector<int> optimal = arr;
    obj.nextPermutationOptimal(optimal);
    cout << "Optimal Approach: ";
    printArray(optimal);

    return 0;
}