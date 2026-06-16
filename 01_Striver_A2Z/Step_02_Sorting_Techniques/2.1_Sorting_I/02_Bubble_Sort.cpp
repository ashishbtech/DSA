#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int didSwap = 0;

            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);

                    didSwap = 1;
                }
            }
            // If no two elements were swapped by inner loop, then break (Optimized)
            if (didSwap == 0)
                break;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    obj.bubbleSort(arr);

    cout << "Bubble Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}