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
private:
    Node *reverseList(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    Node *getKthNode(Node *temp, int k)
    {
        k -= 1;
        while (temp != nullptr && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

public:
    // Helper: Convert array to Linked List
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

    // OPTIMAL: Segmented Reversal
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *reverseKGroup(Node *head, int k)
    {
        Node *temp = head;
        Node *prevLast = nullptr; // Tracks the tail of the previously reversed group

        while (temp != nullptr)
        {
            // Find the Kth node for the current group
            Node *kThNode = getKthNode(temp, k);

            // If we don't have k nodes left, just attach the remainder and stop
            if (kThNode == nullptr)
            {
                if (prevLast != nullptr)
                {
                    prevLast->next = temp;
                }
                break;
            }

            // Secure the rest of the list
            Node *nextNode = kThNode->next;

            // Sever the link to isolate this chunk of k nodes
            kThNode->next = nullptr;

            // Reverse the isolated chunk
            reverseList(temp);

            // Reconnect the chunk to the main list
            if (temp == head)
            {
                // If it's the very first group, the new head is the Kth node
                head = kThNode;
            }
            else
            {
                // Otherwise, link the previous group's tail to this group's new head
                prevLast->next = kThNode;
            }

            // 'temp' (the original head of this chunk) is now its tail.
            // Save it for the next iteration.
            prevLast = temp;

            // Move on to the next group
            temp = nextNode;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;

    Node *head = obj.convertArrToLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    head = obj.reverseKGroup(head, k);

    cout << "Reversed (k=" << k << "): ";
    obj.printLL(head);

    return 0;
}