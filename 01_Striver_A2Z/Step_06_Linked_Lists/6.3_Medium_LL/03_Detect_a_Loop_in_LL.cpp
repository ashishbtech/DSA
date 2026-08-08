#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

class Solution
{
public:
    // Helper: Build a linked list and intentionally create a cycle for testing
    Node *createListWithCycle()
    {
        Node *head = new Node(1);
        Node *node2 = new Node(2);
        Node *node3 = new Node(3);
        Node *node4 = new Node(4);
        Node *node5 = new Node(5);

        head->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        // CREATE THE LOOP: Tail (5) points back to Node 3
        node5->next = node3;

        return head;
    }

    // Helper: Build a normal, straight linked list
    Node *createListWithoutCycle()
    {
        Node *head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        return head;
    }

    // 1. BRUTE FORCE: Store visited node addresses in a Hash Set
    // Time Complexity: O(N) | Space Complexity: O(N)
    bool hasCycleBrute(Node *head)
    {
        unordered_set<Node *> visited;
        Node *temp = head;

        while (temp != nullptr)
        {

            if (visited.find(temp) != visited.end())
            {
                return true;
            }

            visited.insert(temp);
            temp = temp->next;
        }

        return false;
    }

    // 2. OPTIMAL: Floyd's Tortoise and Hare Algorithm
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool hasCycleOptimal(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    Node *cycleList = obj.createListWithCycle();
    Node *straightList = obj.createListWithoutCycle();

    cout << "Checking list WITH cycle:\n";
    cout << "Brute Force : " << (obj.hasCycleBrute(cycleList) ? "True (Loop Detected)" : "False") << "\n";
    cout << "Optimal     : " << (obj.hasCycleOptimal(cycleList) ? "True (Loop Detected)" : "False") << "\n\n";

    cout << "Checking list WITHOUT cycle:\n";
    cout << "Optimal     : " << (obj.hasCycleOptimal(straightList) ? "True (Loop Detected)" : "False") << "\n";

    return 0;
}