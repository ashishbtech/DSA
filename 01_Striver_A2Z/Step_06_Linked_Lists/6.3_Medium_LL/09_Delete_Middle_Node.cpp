#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

class Solution {
public:
    Node* convertArrToLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            mover->next = new Node(arr[i]);
            mover = mover->next;
        }
        return head;
    }

    void printLL(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // 1. BRUTE FORCE: Count nodes, then traverse to the one before middle
    // Time Complexity: O(N + N/2) | Space Complexity: O(1)
    Node* deleteMiddleBrute(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Count length
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Traverse to (N/2) - 1
        int targetIdx = (count / 2) - 1;
        temp = head;
        while (targetIdx > 0) {
            targetIdx--;
            temp = temp->next;
        }

        // temp is now right before the middle node
        Node* middleNode = temp->next;
        temp->next = temp->next->next;
        delete middleNode;

        return head;
    }

    // 2. OPTIMAL: Fast and Slow pointers with Fast offset
    // Time Complexity: O(N/2) | Space Complexity: O(1)
    Node* deleteMiddleOptimal(Node* head) {
        
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        Node* slow = head;
        // Give 'fast' a 2-step head start
        Node* fast = head->next->next; 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'slow' is now positioned exactly one node BEFORE the middle node
        Node* middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode;

        return head;
    }
};

int main() {
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {1};

   

    Node* head1 = obj.convertArrToLL(arr1);
    cout << "Odd List  : ";
    obj.printLL(head1);
    head1 = obj.deleteMiddleOptimal(head1);
    cout << "After Del : ";
    obj.printLL(head1);
    cout << "\n";

    Node* head2 = obj.convertArrToLL(arr2);
    cout << "Even List : ";
    obj.printLL(head2);
    head2 = obj.deleteMiddleOptimal(head2);
    cout << "After Del : ";
    obj.printLL(head2);
    cout << "\n";

    Node* head3 = obj.convertArrToLL(arr3);
    cout << "Single    : ";
    obj.printLL(head3);
    head3 = obj.deleteMiddleOptimal(head3);
    cout << "After Del : ";
    if (!head3) cout << "NULL\n";

    return 0;
}