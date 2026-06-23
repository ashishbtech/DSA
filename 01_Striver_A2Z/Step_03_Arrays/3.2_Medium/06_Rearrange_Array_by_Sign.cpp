#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 1. BRUTE: Collect into two dynamic vectors via push_back (2 Passes)
    // Time Complexity: O(2N) | Space Complexity: O(N)
    vector<int> rearrangeBrute(vector<int> &arr)
    {
        vector<int> pos;
        vector<int> neg;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        for (int i = 0; i < n / 2; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        return arr;
    }

    // 2. BETTER: Same logic, but pre-allocate vector sizes to bypass doubling overhead
    // Time Complexity: O(2N) | Space Complexity: O(N)
    vector<int> rearrangeBetter(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pos(n / 2, 0);
        vector<int> neg(n / 2, 0);
        int p = 0, ng = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                pos[p++] = arr[i];
            else
                neg[ng++] = arr[i];
        }

        for (int i = 0; i < n / 2; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        return arr;
    }

    // 3. OPTIMAL: Single pass using two leaping target pointers
    // Time Complexity: strictly O(N) | Space Complexity: O(N) for answer array
    vector<int> rearrangeOptimal(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                ans[posIndex] = arr[i];
                posIndex += 2;
            }
            else
            {
                ans[negIndex] = arr[i];
                negIndex += 2;
            }
        }
        return ans;
    }

    // --- (Variant 2) ---
    // "What if the array has an UNEQUAL number of positives and negatives?"
    // Time Complexity: O(2N) | Space Complexity: O(N)
    vector<int> rearrangeUnequal(vector<int> &arr)
    {
        vector<int> pos, neg;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        if (pos.size() < neg.size())
        {
            for (int i = 0; i < pos.size(); i++)
            {
                arr[2 * i] = pos[i];
                arr[2 * i + 1] = neg[i];
            }
            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++)
            {
                arr[index++] = neg[i];
            }
        }
        else
        {
            for (int i = 0; i < neg.size(); i++)
            {
                arr[2 * i] = pos[i];
                arr[2 * i + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++)
            {
                arr[index++] = pos[i];
            }
        }
        return arr;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    cout << "--- Problem 6: Rearrange Array by Sign ---\n\n";

    vector<int> t1 = arr;
    vector<int> resBrute = obj.rearrangeBrute(t1);
    cout << "Brute   : [ ";
    for (int x : resBrute)
        cout << x << " ";
    cout << "]\n";

    vector<int> t2 = arr;
    vector<int> resBetter = obj.rearrangeBetter(t2);
    cout << "Better  : [ ";
    for (int x : resBetter)
        cout << x << " ";
    cout << "]\n";

    vector<int> t3 = arr;
    vector<int> resOptimal = obj.rearrangeOptimal(t3);
    cout << "Optimal : [ ";
    for (int x : resOptimal)
        cout << x << " ";
    cout << "]\n\n";

    vector<int> unequal = {-1, 2, 3, 4, -3, 1}; // 4 Positives, 2 Negatives
    cout << "Variant 2 (Unequal Input: [-1, 2, 3, 4, -3, 1])\nOutput  : [ ";
    vector<int> resUnequal = obj.rearrangeUnequal(unequal);
    for (int x : resUnequal)
        cout << x << " ";
    cout << "]\n";

    return 0;
}