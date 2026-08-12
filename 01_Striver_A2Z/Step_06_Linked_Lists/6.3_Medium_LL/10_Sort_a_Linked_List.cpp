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
private:
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* mergeTwoSortedLists(Node* list1, Node* list2) {
        Node dummy(-1); 
        Node* temp = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data < list2->data) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1 != nullptr) temp->next = list1;
        else temp->next = list2;

        return dummy.next;
    }

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

    // 1. BRUTE FORCE: Extract to array, sort, and overwrite
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    Node* sortListBrute(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;

        vector<int> arr;
        Node* temp = head;
        
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->data = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }

    // 2. OPTIMAL: Merge Sort on Pointers
    // Time Complexity: O(N log N) | Space Complexity: O(1) auxiliary (ignoring O(log N) recursive stack)
    Node* sortListOptimal(Node* head) {
       
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Step 1: Divide the list into two halves
        Node* middle = findMiddle(head);
        Node* leftHead = head;
        Node* rightHead = middle->next;
        
        // Sever the connection to completely split the lists
        middle->next = nullptr;

        // Step 2: Recursively sort both halves
        leftHead = sortListOptimal(leftHead);
        rightHead = sortListOptimal(rightHead);

        // Step 3: Merge the sorted halves
        return mergeTwoSortedLists(leftHead, rightHead);
    }
};

int main() {
    Solution obj;
    vector<int> arr = {4, 2, 1, 3, 5, 8, 7, 6};

    

    Node* head = obj.convertArrToLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    head = obj.sortListOptimal(head);
    
    cout << "Sorted List   : ";
    obj.printLL(head);

    return 0;
}