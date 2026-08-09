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

        node5->next = node3;

        return head;
    }

    // 1. BRUTE FORCE: Store visited node addresses in a Hash Set
    // Time Complexity: O(N) | Space Complexity: O(N)
    Node *detectCycleBrute(Node *head)
    {
        unordered_set<Node *> visited;
        Node *temp = head;

        while (temp != nullptr)
        {
            if (visited.find(temp) != visited.end())
            {
                return temp;
            }
            visited.insert(temp);
            temp = temp->next;
        }

        return nullptr;
    }

    // 2. OPTIMAL: Floyd's Tortoise and Hare Phase 2
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *detectCycleOptimal(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {

                slow = head;

                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main()
{
    Solution obj;

    Node *cycleList = obj.createListWithCycle();

    Node *startNodeBrute = obj.detectCycleBrute(cycleList);
    if (startNodeBrute)
    {
        cout << "Brute Force : Cycle starts at node with data " << startNodeBrute->data << "\n";
    }

    Node *startNodeOptimal = obj.detectCycleOptimal(cycleList);
    if (startNodeOptimal)
    {
        cout << "Optimal     : Cycle starts at node with data " << startNodeOptimal->data << "\n";
    }

    return 0;
}