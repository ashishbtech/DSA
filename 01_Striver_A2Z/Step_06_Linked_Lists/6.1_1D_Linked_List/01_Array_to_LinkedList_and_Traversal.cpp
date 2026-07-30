#include <bits/stdc++.h>
using namespace std;

// 1. The structural blueprint of a singly linked list node
struct Node
{
    int data;   // The stored value
    Node *next; // Pointer to the next node in memory

    // Constructor for easy node initialization
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

class Solution
{
public:
    // Convert a 1D vector into a dynamically linked list on the heap
    // Time Complexity: O(N) | Space Complexity: O(N) for heap allocation
    Node *convertArrToLL(vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;

        // Step 1: Create the immutable head pointer
        Node *head = new Node(arr[0]);
        Node *mover = head;

        // Step 2: Iterate through remaining elements and chain them together
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            mover->next = temp; // Link previous node to current node
            mover = temp;       // Advance the mover pointer
        }

        return head;
    }

    // Traverse and print all elements in the linked list
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    void printLL(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Calculate the total number of nodes in the linked list
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    int lengthOfLL(Node *head)
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Search for a specific target value inside the linked list
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    bool checkIfPresent(Node *head, int target)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == target)
            {
                return true; // Target found!
            }
            temp = temp->next;
        }
        return false; // Reached nullptr without finding target
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 5, 8, 7, 3};

    // Build the linked list from the array
    Node *head = obj.convertArrToLL(arr);

    // 1. Print traversal
    cout << "Linked List Traversal: ";
    obj.printLL(head);

    // 2. Print length
    cout << "Length of Linked List: " << obj.lengthOfLL(head) << "\n";

    // 3. Search for elements
    int target1 = 8;
    int target2 = 100;
    cout << "Is " << target1 << " present? " << (obj.checkIfPresent(head, target1) ? "Yes" : "No") << "\n";
    cout << "Is " << target2 << " present? " << (obj.checkIfPresent(head, target2) ? "Yes" : "No") << "\n";

    return 0;
}