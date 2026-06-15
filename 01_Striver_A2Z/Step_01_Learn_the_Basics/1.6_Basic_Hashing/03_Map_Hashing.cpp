#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    void findHighestAndLowestFreq(const vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (int num : arr) {
            mpp[num]++;
        }

        int maxFreq = 0, minFreq = INT_MAX;
        int maxElement = 0, minElement = 0;

        for (auto it : mpp) {
            int element = it.first;
            int count = it.second;

            if (count > maxFreq) {
                maxFreq = count;
                maxElement = element;
            }
            if (count < minFreq) {
                minFreq = count;
                minElement = element;
            }
        }

        cout << "Highest Frequency Element: " << maxElement << " (Count: " << maxFreq << ")\n";
        cout << "Lowest Frequency Element: " << minElement << " (Count: " << minFreq << ")\n";
    }
};

int main() {
    Solution obj;
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    obj.findHighestAndLowestFreq(arr);
    return 0;
}