// Interviewers sometimes ask you to convert iterative algorithms to recursive ones just to test your mastery of the Call Stack.
//  Here are Bubble and Insertion sort written purely with recursion.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void recursiveBubbleSort(vector<int> &arr, int n)
    {
        if (n == 1)
            return; // Base case

        int didSwap = 0;
        for (int j = 0; j <= n - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            return; // Optimization if already sorted

        recursiveBubbleSort(arr, n - 1);
    }

    void recursiveInsertionSort(vector<int> &arr, int i, int n)
    {
        if (i == n)
            return; // Base case

        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }

        recursiveInsertionSort(arr, i + 1, n);
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {13, 46, 24, 52, 20, 9};
    vector<int> arr2 = {13, 46, 24, 52, 20, 9};

    obj.recursiveBubbleSort(arr1, arr1.size());
    obj.recursiveInsertionSort(arr2, 0, arr2.size());

    cout << "Recursive Bubble Sort: ";
    for (int num : arr1)
        cout << num << " ";
    cout << "\nRecursive Insertion Sort: ";
    for (int num : arr2)
        cout << num << " ";
    cout << endl;

    return 0;
}