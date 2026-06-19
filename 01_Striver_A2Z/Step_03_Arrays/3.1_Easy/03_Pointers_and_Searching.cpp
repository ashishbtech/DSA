// Logic: Moving zeros to the end while maintaining the relative order of non-zero elements. Again, using the two-pointer technique.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Two-pointer approach
    void moveZerosToEnd(vector<int> &arr)
    {
        int j = -1;
        // Find the first zero
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }
        // If no zero exists
        if (j == -1)
            return;

        // Swap non-zeros with the zero at j
        for (int i = j + 1; i < arr.size(); i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }

    int linearSearch(vector<int> &arr, int num)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == num)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    obj.moveZerosToEnd(arr);

    cout << "Array after moving zeros: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cout << "Index of 4: " << obj.linearSearch(arr, 4) << endl;

    return 0;
}