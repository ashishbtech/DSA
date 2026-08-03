#include <bits/stdc++.h>
using namespace std;

// Blueprint of a Doubly Linked List Node
struct Node
{
    int data;
    Node *next;
    Node *prev; //  backward pointer!

    Node(int data1, Node *next1 = nullptr, Node *prev1 = nullptr)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    // Convert a 1D vector into a Doubly Linked List
    // Time Complexity: O(N) | Space Complexity: O(N) for heap allocation
    Node *convertArrToDLL(vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;

        // Step 1: Create the head node (its prev is automatically nullptr)
        Node *head = new Node(arr[0]);

        // Step 2: Keep track of the previous node as we build the chain
        Node *prevNode = head;

        // Step 3: Iterate and build bi-directional links
        for (int i = 1; i < arr.size(); i++)
        {
            // Instantiate new node, pointing its 'prev' back to 'prevNode'
            Node *temp = new Node(arr[i], nullptr, prevNode);

            // Point the 'prevNode' forward to 'temp'
            prevNode->next = temp;

            prevNode = temp;
        }

        return head;
    }

    // printing function
    void printForward(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 5, 8, 7};

    Node *head = obj.convertArrToDLL(arr);

    cout << "DLL Traversal: ";
    obj.printForward(head);

    return 0;
}