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

    // 1. INSERT AT HEAD
    Node *insertHead(Node *head, int val)
    {

        Node *newNode = new Node(val, head, nullptr);

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        return newNode;
    }

    // 2. INSERT AT tail
    Node *insertTail(Node *head, int val)
    {
        if (head == nullptr)
        {
            return insertHead(head, val);
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(val, nullptr, temp);
        temp->next = newNode;

        return head;
    }

    // 3. INSERT AT K-TH POSITION (Insert BEFORE the current K-th node)
    Node *insertPositionK(Node *head, int val, int k)
    {
        if (k == 1)
        {
            return insertHead(head, val);
        }

        Node *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            if (count == k)
                break;
            temp = temp->next;
        }

        if (temp == nullptr)
            return head;

        Node *back = temp->prev;

        Node *newNode = new Node(val, temp, back);
        back->next = newNode;
        temp->prev = newNode;

        return head;
    }

    // 4. INSERT BEFORE VALUE X
    Node *insertBeforeValue(Node *head, int val, int x)
    {
        if (head == nullptr)
            return nullptr;

        if (head->data == x)
        {
            return insertHead(head, val);
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == x)
                break;
            temp = temp->next;
        }

        if (temp == nullptr)
            return head;

        Node *back = temp->prev;

        Node *newNode = new Node(val, temp, back);
        back->next = newNode;
        temp->prev = newNode;

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 5, 8, 7};

    Node *head = obj.convertArrToDLL(arr);
    cout << "Original DLL                  : ";
    obj.printLL(head);

    // 1. Insert 100 at Head
    head = obj.insertHead(head, 100);
    cout << "Insert 100 at Head            : ";
    obj.printLL(head);

    // 2. Insert 99 at Tail
    head = obj.insertTail(head, 99);
    cout << "Insert 99 at Tail             : ";
    obj.printLL(head);

    // 3. Insert 50 at 3rd Position

    head = obj.insertPositionK(head, 50, 3);
    cout << "Insert 50 at 3rd Position     : ";
    obj.printLL(head);

    // 4. Insert 77 before value 8

    head = obj.insertBeforeValue(head, 77, 8);
    cout << "Insert 77 before value 8      : ";
    obj.printLL(head);

    return 0;
}