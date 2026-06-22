#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Standard intro-sort
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    void sortColorsBrute(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
    }

    // 2. BETTER: The Counting Approach (2 Passes)
    // Time Complexity: O(2N) | Space Complexity: O(1)
    void sortColorsBetter(vector<int> &arr)
    {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // Pass 1: Count frequencies
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0) cnt0++;
            else if(arr[i] == 1) cnt1++;
            else cnt2++;
        }

        // Pass 2: Overwrite array manually
        int index = 0;
        for (int i = 0; i < cnt0; i++)
            arr[index++] = 0;
        for (int i = 0; i < cnt1; i++)
            arr[index++] = 1;
        for (int i = 0; i < cnt2; i++)
            arr[index++] = 2;
    }

    // 3. OPTIMAL: Dutch National Flag Algorithm (1 Pass via 3 Pointers)
    // Time Complexity: O(N) strictly | Space Complexity: O(1)
    void sortColorsOptimal(vector<int> &arr)
    {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            { 
                swap(arr[mid], arr[high]);
                high--;
            
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> raw = {2, 0, 2, 1, 1, 0};

    vector<int> t1 = raw;
    obj.sortColorsBrute(t1);
    cout << "Brute   : ";
    for (int x : t1) cout << x << " ";
    cout << "\n";

    vector<int> t2 = raw;
    obj.sortColorsBetter(t2);
    cout << "Better  : ";
    for (int x : t2) cout << x << " ";
    cout << "\n";

    vector<int> t3 = raw;
    obj.sortColorsOptimal(t3);
    cout << "Optimal : ";
    for (int x : t3) cout << x << " ";
    cout << "\n";

    return 0;
}