#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: 4 nested loops + a Set to handle duplicate quadruplets
    // Time Complexity: O(N^4) | Space Complexity: O(2 * unique quadruplets)
    vector<vector<int>> fourSumBrute(vector<int> &arr, int target)
    {
        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];

                        if (sum == target)
                        {
                            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // 2. BETTER: 3 nested loops + Hash Set to search for the 4th required complement
    // Time Complexity: O(N^3 * log(unique)) | Space Complexity: O(N) + O(unique)
    vector<vector<int>> fourSumBetter(vector<int> &arr, int target)
    {
        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                unordered_set<long long> hashSet;
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = (long long)arr[i] + arr[j] + arr[k];
                    long long fourth = target - sum;

                    if (hashSet.find(fourth) != hashSet.end())
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(arr[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // 3. OPTIMAL: Sort first, fix anchors 'i' and 'j', then collapse with two pointers 'k' and 'l'
    // Time Complexity: O(N^3) | Space Complexity: O(1) auxiliary space
    vector<vector<int>> fourSumOptimal(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {

                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];

                    if (sum < target)
                    {
                        k++;
                    }
                    else if (sum > target)
                    {
                        l--;
                    }
                    else
                    {
                        ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                        k++;
                        l--;

                        while (k < l && arr[k] == arr[k - 1])
                            k++;
                        while (k < l && arr[l] == arr[l + 1])
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> r1 = obj.fourSumBrute(arr, target);
    cout << "Brute   : " << r1.size() << " quadruplets found\n";

    vector<vector<int>> r2 = obj.fourSumBetter(arr, target);
    cout << "Better  : " << r2.size() << " quadruplets found\n";

    vector<vector<int>> r3 = obj.fourSumOptimal(arr, target);
    cout << "Optimal :\n";
    for (auto &quad : r3)
    {
        cout << "[ " << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << " ]\n";
    }

    return 0;
}