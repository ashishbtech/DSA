#include <bits/stdc++.h>
using namespace std;

// Blueprint of our Singly Linked List Node
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

    // 1. DELETE HEAD
    // Time Complexity: O(1) | Space Complexity: O(1)
    Node *deleteHead(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *temp = head; // Save the old head
        head = head->next; // Advance head to node 2
        delete temp;       // Release old head from heap memory
        return head;
    }

    // 2. DELETE TAIL
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *deleteTail(Node *head)
    {
        // If list is empty or has only 1 node, deleting tail leaves an empty list
        if (head == nullptr || head->next == nullptr)
        {
            delete head;
            return nullptr;
        }

        Node *temp = head;
        // Stop when temp is at the second-to-last node
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;    // Free the actual tail node
        temp->next = nullptr; // Sever the connection
        return head;
    }

    // 3. DELETE K-TH NODE (1-indexed)
    // Time Complexity: O(K) | Space Complexity: O(1)
    Node *deleteKthNode(Node *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        if (k == 1)
            return deleteHead(head);

        int count = 0;
        Node *temp = head;
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            count++;
            if (count == k)
            {
                // Rewire prev's next pointer to skip the current node
                prev->next = prev->next->next;
                delete temp; // Free the detached node
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }

    // 4. DELETE NODE BY VALUE
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *deleteByValue(Node *head, int val)
    {
        if (head == nullptr)
            return nullptr;

        // If the head itself holds the target value
        if (head->data == val)
        {
            return deleteHead(head);
        }

        Node *temp = head;
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 5, 8, 7, 3};

    Node *head = obj.convertArrToLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    // 1. Test Delete Head
    head = obj.deleteHead(head);
    cout << "After deleting Head (12)      : ";
    obj.printLL(head);

    // 2. Test Delete Tail
    head = obj.deleteTail(head);
    cout << "After deleting Tail (3)       : ";
    obj.printLL(head);

    // 3. Test Delete K-th Node (Delete 2nd node, which is 8)
    head = obj.deleteKthNode(head, 2);
    cout << "After deleting 2nd Node (8)   : ";
    obj.printLL(head);

    // 4. Test Delete by Value (Delete node with value 7)
    head = obj.deleteByValue(head, 7);
    cout << "After deleting Value (7)      : ";
    obj.printLL(head);

    return 0;
}