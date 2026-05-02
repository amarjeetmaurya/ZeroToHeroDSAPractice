// 206. Reverse Linked List

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ================================================================

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};
// +++++++++++++++++++++++
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * temp = head;
        ListNode * newHead = nullptr;
        while(temp != nullptr) { 
            ListNode * newNode = new ListNode(temp->val);
            newNode->next = newHead;
            newHead = newNode;
            temp = temp->next;
        }
        return newHead;
    }
};
// +++++++++++++++++++++++
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * temp = head;
        ListNode * prev = nullptr;
        while(temp != nullptr) { 
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
};

// ================================================================


// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a sample list
ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

int main() {
    Solution sol;

    // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList();
    cout << "Original list: ";
    printList(head);

    // Reverse the list
    ListNode* reversed = sol.reverseList(head);
    cout << "Reversed list: ";
    printList(reversed);

    return 0;
}
