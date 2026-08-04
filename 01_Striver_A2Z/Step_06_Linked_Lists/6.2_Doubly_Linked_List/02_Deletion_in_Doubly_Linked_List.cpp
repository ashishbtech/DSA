#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

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
    // Convert array to DLL for testing
    Node *convertArrToDLL(vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;
        Node *head = new Node(arr[0]);
        Node *prevNode = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr, prevNode);
            prevNode->next = temp;
            prevNode = temp;
        }
        return head;
    }

    // Print the entire DLL
    void printLL(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // 1. DELETE HEAD
    Node *deleteHead(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;

        delete temp;
        return head;
    }

    // 2. DELETE TAIL
    Node *deleteTail(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return deleteHead(head);

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *newTail = temp->prev;
        newTail->next = nullptr;
        temp->prev = nullptr;

        delete temp;
        return head;
    }

    // 3. DELETE K-TH NODE (1-indexed)
    Node *deleteKthNode(Node *head, int k)
    {
        if (head == nullptr)
            return nullptr;

        int count = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            if (count == k)
                break;
            temp = temp->next;
        }

        // If K is out of bounds
        if (temp == nullptr)
            return head;

        Node *back = temp->prev;
        Node *front = temp->next;

        // If it's the head node
        if (back == nullptr && front == nullptr)
        {
            delete temp;
            return nullptr;
        }
        else if (back == nullptr)
            return deleteHead(head);
        else if (front == nullptr)
            return deleteTail(head);

        // Standard middle node deletion
        back->next = front;
        front->prev = back;

        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 5, 8, 7, 3};

    Node *head = obj.convertArrToDLL(arr);
    cout << "Original DLL                  : ";
    obj.printLL(head);

    // 1. Delete Head (12)
    head = obj.deleteHead(head);
    cout << "After deleting Head (12)      : ";
    obj.printLL(head);

    // 2. Delete Tail (3)
    head = obj.deleteTail(head);
    cout << "After deleting Tail (3)       : ";
    obj.printLL(head);

    // 3. Delete 2nd Node (8)
    head = obj.deleteKthNode(head, 2);
    cout << "After deleting 2nd Node (8)   : ";
    obj.printLL(head);

    return 0;
}