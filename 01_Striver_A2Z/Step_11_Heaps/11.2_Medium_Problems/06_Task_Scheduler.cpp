#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // MATH APPROACH: Find the mathematical lower bound
    // Time Complexity: O(N) | Space Complexity: O(1)
    int leastIntervalMath(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxFreqCount = 0;

        for (char task : tasks)
        {
            freq[task - 'A']++;
            if (freq[task - 'A'] > maxFreq)
            {
                maxFreq = freq[task - 'A'];
                maxFreqCount = 1;
            }
            else if (freq[task - 'A'] == maxFreq)
            {
                maxFreqCount++;
            }
        }

        int timeByFormula = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return max((int)tasks.size(), timeByFormula);
    }

    // OPTIMAL HEAP APPROACH: Simulation using Max Heap and Cooldown Queue
    // Time Complexity: O(N) | Space Complexity: O(1)
    int leastIntervalOptimal(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }

        // Max Heap to store frequencies
        priority_queue<int> maxHeap;
        for (int count : freq)
        {
            if (count > 0)
            {
                maxHeap.push(count);
            }
        }

        // Queue stores {remaining_frequency, unlock_time}
        queue<pair<int, int>> cooldownQueue;
        int time = 0;

        while (!maxHeap.empty() || !cooldownQueue.empty())
        {
            time++;

            // 1. Process the most frequent available task
            if (!maxHeap.empty())
            {
                int currentFreq = maxHeap.top();
                maxHeap.pop();
                currentFreq--;

                // If the task still needs to be run, put it in cooldown
                if (currentFreq > 0)
                {
                    cooldownQueue.push({currentFreq, time + n});
                }
            }

            // 2. Check if the task at the front of the queue has cooled down
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time)
            {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return time;
    }
};

int main()
{
    Solution obj;

    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    cout << "Tasks: [A, A, A, B, B, B] | Cooldown (n): 2\n";
    cout << "Math: " << obj.leastIntervalMath(tasks1, n1) << "\n";
    cout << "Optimal (Heap): " << obj.leastIntervalOptimal(tasks1, n1) << "\n";

    cout << "---\n";

    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;
    cout << "Tasks: [A, C, A, B, D, B] | Cooldown (n): 1\n";
    cout << "Optimal (Heap): " << obj.leastIntervalOptimal(tasks2, n2) << "\n";

    cout << "---\n";

    vector<char> tasks3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n3 = 2;
    cout << "Tasks: 6 As, 1 of B through G | Cooldown (n): 2\n";
    cout << "Optimal (Heap): " << obj.leastIntervalOptimal(tasks3, n3) << "\n";

    return 0;
}