// Logic: Pick a pivot element. Place it in its exact correct sorted position.
// Move everything smaller than the pivot to the left, and everything larger to the right. Repeat.
//  Time Complexity: O(N \log N) average,
//  Space Complexity: O(1) auxiliary.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            // Find first element greater than pivot from left
            while (arr[i] <= pivot && i <= high - 1)
            {
                i++;
            }
            // Find first element smaller than pivot from right
            while (arr[j] > pivot && j >= low + 1)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        // Place pivot in correct position
        swap(arr[low], arr[j]);
        return j;
    }

public:
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pIndex = partition(arr, low, high);
            quickSort(arr, low, pIndex - 1);  // Sort left partition
            quickSort(arr, pIndex + 1, high); // Sort right partition
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    obj.quickSort(arr, 0, n - 1);

    cout << "Quick Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}