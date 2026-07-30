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
    // Helper: Convert array to Linked List for testing
    Node *convertArrToLL(vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;
        Node *head = new Node(arr[0]);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            mover->next = new Node(arr[i]);
            mover = mover->next;
        }
        return head;
    }

    // Helper: Print the entire linked list
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

    // 1. INSERT AT HEAD
    // Time Complexity: O(1) | Space Complexity: O(1) auxiliary
    Node *insertHead(Node *head, int val)
    {
        // Create new node and point its next to the current head
        Node *temp = new Node(val, head);
        return temp; // Return the new head
    }

    // 2. INSERT AT TAIL
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    Node *insertTail(Node *head, int val)
    {
        if (head == nullptr)
        {
            return new Node(val);
        }

        Node *temp = head;
        // Traverse until we are standing on the very last node
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // Create new node and link it to the current tail
        temp->next = new Node(val);
        return head;
    }

    // 3. INSERT AT K-TH POSITION (1-indexed)
    // Time Complexity: O(K) | Space Complexity: O(1) auxiliary
    Node *insertPositionK(Node *head, int val, int k)
    {
        if (head == nullptr)
        {
            if (k == 1)
                return new Node(val);
            return head;
        }
        if (k == 1)
        {
            return new Node(val, head);
        }

        int count = 0;
        Node *temp = head;

        // Traverse to find the (K-1)th node
        while (temp != nullptr)
        {
            count++;
            if (count == k - 1)
            {
                // Splice the new node in between temp and temp->next
                Node *newNode = new Node(val, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }

    // 4. INSERT BEFORE VALUE X
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    Node *insertBeforeValue(Node *head, int val, int x)
    {
        if (head == nullptr)
            return nullptr;
        if (head->data == x)
        {
            return new Node(val, head);
        }

        Node *temp = head;

        // Look one node ahead to find value 'x'
        while (temp->next != nullptr)
        {
            if (temp->next->data == x)
            {
                // Splice the new node right before the node containing 'x'
                Node *newNode = new Node(val, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 5, 8, 7};



    Node *head = obj.convertArrToLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    // 1. Test Insert at Head (Insert 100)
    head = obj.insertHead(head, 100);
    cout << "Insert 100 at Head            : ";
    obj.printLL(head);

    // 2. Test Insert at Tail (Insert 99)
    head = obj.insertTail(head, 99);
    cout << "Insert 99 at Tail             : ";
    obj.printLL(head);

    // 3. Test Insert at 3rd Position (Insert 50)
    // Current: 100 -> 12 -> 5 -> 8 -> 7 -> 99
    // Expected: 100 -> 12 -> 50 -> 5 -> 8 -> 7 -> 99
    head = obj.insertPositionK(head, 50, 3);
    cout << "Insert 50 at 3rd Position     : ";
    obj.printLL(head);

    // 4. Test Insert Before Value 8 (Insert 77)
    // Expected: 100 -> 12 -> 50 -> 5 -> 77 -> 8 -> 7 -> 99
    head = obj.insertBeforeValue(head, 77, 8);
    cout << "Insert 77 before value 8      : ";
    obj.printLL(head);

    return 0;
}