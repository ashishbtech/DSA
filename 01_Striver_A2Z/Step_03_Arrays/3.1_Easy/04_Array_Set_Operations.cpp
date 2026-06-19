// Logic: Finding the union of two sorted arrays without using a std::set.
// By using two pointers (i and j), we can merge them in linear O(N + M) time while skipping duplicates on the fly.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Optimal O(N + M) Time, O(1) Auxiliary Space
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<int> unionArr;

        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                if (unionArr.empty() || unionArr.back() != a[i])
                {
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if (unionArr.empty() || unionArr.back() != b[j])
                {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }

        // Catch remaining elements in array a
        while (i < n)
        {
            if (unionArr.empty() || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }

        // Catch remaining elements in array b
        while (j < m)
        {
            if (unionArr.empty() || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }

        return unionArr;
    }
};

int main()
{
    Solution obj;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b = {2, 3, 4, 4, 5, 11, 12};

    vector<int> result = obj.findUnion(a, b);
    cout << "Union of arrays: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}