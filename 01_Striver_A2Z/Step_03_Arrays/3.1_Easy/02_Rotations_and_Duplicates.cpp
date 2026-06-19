// Logic: Removing duplicates in-place using a two-pointer approach (O(N) time, O(1) space).
//  Rotating arrays by k steps using the legendary mathematical reversal algorithm.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Two-pointer approach to modify array in-place
    int removeDuplicates(vector<int> &arr)
    {
        int i = 0;
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[i] != arr[j])
            {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1; // Returns the size of the unique array
    }

    // Optimal O(N) Time, O(1) Space rotation using reversals
    void leftRotateByK(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n; // If k > n
        if (k == 0) return;
        
        // Reverse first k elements
        reverse(arr.begin(), arr.begin() + k);
        // Reverse last n-k elements
        reverse(arr.begin() + k, arr.end());
        // Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 1, 2, 2, 2, 3, 3};
    int uniqueSize = obj.removeDuplicates(arr1);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueSize; i++)
        cout << arr1[i] << " ";
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    obj.leftRotateByK(arr2, 3);
    cout << "Array after left rotating by 3: ";
    for (int num : arr2)
        cout << num << " ";
    cout << endl;

    return 0;
}