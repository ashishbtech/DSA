#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void explainPQ() {
        // Max Heap (Largest element stays at the top)
        priority_queue<int> pq;
        pq.push(5);
        pq.push(2);
        pq.push(8);
        cout << "Max Heap Top: " << pq.top() << endl; // Prints 8

        // Min Heap (Smallest element stays at the top)
        priority_queue<int, vector<int>, greater<int>> minPQ;
        minPQ.push(5);
        minPQ.push(2);
        minPQ.push(8);
        cout << "Min Heap Top: " << minPQ.top() << endl; // Prints 2
    }
};

int main() {
    Solution obj;
    cout << "--- Priority Queues ---" << endl;
    obj.explainPQ();
    return 0;
}