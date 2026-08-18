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

    // OPTIMAL: 1-Pass Weaving
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *deleteAllOccurrences(Node *head, int k)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == k)
            {

                if (temp == head)
                {
                    head = head->next;
                }

                Node *nextNode = temp->next;
                Node *prevNode = temp->prev;

                if (prevNode != nullptr)
                {
                    prevNode->next = nextNode;
                }

                if (nextNode != nullptr)
                {
                    nextNode->prev = prevNode;
                }

                Node *delNode = temp;
                temp = temp->next;
                delete delNode;
            }
            else
            {

                temp = temp->next;
            }
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    int key = 10;

    Node *head = obj.convertArrToDLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    head = obj.deleteAllOccurrences(head, key);

    cout << "After Deleting " << key << ": ";
    obj.printLL(head);

    return 0;
}