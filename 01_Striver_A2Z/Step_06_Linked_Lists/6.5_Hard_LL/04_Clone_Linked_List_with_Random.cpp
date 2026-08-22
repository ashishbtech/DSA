#include <bits/stdc++.h>
using namespace std;

// Custom Node class for this problem
struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int data1, Node *next1 = nullptr, Node *random1 = nullptr)
    {
        data = data1;
        next = next1;
        random = random1;
    }
};

class Solution
{
public:
    // Helper: Print list with next and random data for verification
    void printListWithRandom(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Node: " << temp->data;
            if (temp->random != nullptr)
            {
                cout << ", Random: " << temp->random->data;
            }
            else
            {
                cout << ", Random: NULL";
            }
            cout << "\n";
            temp = temp->next;
        }
        cout << "----------------------\n";
    }

    // 1. BRUTE FORCE: Hash Map
    // Time Complexity: O(2N) | Space Complexity: O(N) auxiliary space
    Node *cloneLinkedListBrute(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node *, Node *> mpp;
        Node *temp = head;

        //  1: Create all clone nodes and map them
        while (temp != nullptr)
        {
            mpp[temp] = new Node(temp->data);
            temp = temp->next;
        }

        //  2: Connect next and random pointers using the map
        temp = head;
        while (temp != nullptr)
        {
            Node *cloneNode = mpp[temp];
            cloneNode->next = mpp[temp->next];
            cloneNode->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }

    // 2. OPTIMAL: Interweaving nodes
    // Time Complexity: O(3N) | Space Complexity: O(1) auxiliary space
    Node *cloneLinkedListOptimal(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        // Step 1: Insert clone nodes directly after original nodes
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *cloneNode = new Node(temp->data);
            cloneNode->next = temp->next;
            temp->next = cloneNode;
            temp = cloneNode->next; // Move to the next original node
        }

        // Step 2: Wire the random pointers for the clone nodes
        temp = head;
        while (temp != nullptr)
        {
            if (temp->random != nullptr)
            {
                // cloneNode->random = originalTarget->cloneNode
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next; // Jump to the next original node
        }

        // Step 3: Extract the clone list and restore the original list
        temp = head;
        Node dummy(-1);
        Node *res = &dummy;

        while (temp != nullptr)
        {
            // Extract the clone
            res->next = temp->next;
            res = res->next;

            // Restore the original list's next pointer
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy.next;
    }
};

int main()
{
    Solution obj;

    // Build the test case: 7 -> 13 -> 11 -> 10 -> 1
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    // Set up random pointers
    head->random = nullptr;                                  // 7 -> NULL
    head->next->random = head;                               // 13 -> 7
    head->next->next->random = head->next->next->next->next; // 11 -> 1
    head->next->next->next->random = head->next->next;       // 10 -> 11
    head->next->next->next->next->random = head;             // 1 -> 7

    cout << "Original List:\n";
    obj.printListWithRandom(head);

    Node *clonedHead = obj.cloneLinkedListOptimal(head);

    cout << "Cloned List (Deep Copy):\n";
    obj.printListWithRandom(clonedHead);

    return 0;
}