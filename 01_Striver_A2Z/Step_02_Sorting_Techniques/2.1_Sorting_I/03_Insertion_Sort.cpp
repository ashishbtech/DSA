#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i <= n; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                j--;
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 6, 2, 4, 8, 39, 34, 57};

    obj.insertionSort(arr);

    cout << "Insertion Sorted Array : ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}