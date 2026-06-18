// Largest, Second Largest, Check Sorted
// Logic: Finding the second largest element in a single $O(N)$ pass without sorting the array.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int getLargest(vector<int> &arr)
    {
        int n = arr.size();
        int largest = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > largest)
            {
                largest = arr[i];
            }
        }
        return largest;
    }

    // Optimal O(N) single pass
    int getSecondLargest(vector<int> &arr)
    {
        int largest = arr[0];
        int secondLargest = -1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > largest)
            {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > secondLargest)
            {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }

    bool isSorted(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] >= arr[i - 1])
            {
            }
            else
            {
                return false;
            }
        }

        return true;
    }
    /*  Better O(2N) but not optimized  for 2nd largest*/
    //  int getSecondLargest(vector<int> &arr)
    // {
    //     int n = arr.size();
    //     int largest = arr[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         if (arr[i] > largest)
    //         {
    //             largest = arr[i];
    //         }
    //     }

    //     int SecondLargest = -1;
    //     for(int i = 0; i < n; i++){
    //         if(arr[i] > SecondLargest && arr[i] != largest){
    //             SecondLargest = arr[i];
    //         }
    //     }
    //     return SecondLargest;

    // }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 4, 7, 7, 5};

    cout << "Largest: " << obj.getLargest(arr) << endl;
    cout << "Second Largest: " << obj.getSecondLargest(arr) << endl;
    cout << "Is Sorted? " << (obj.isSorted(arr) ? "Yes" : "No") << endl;

    return 0;
}