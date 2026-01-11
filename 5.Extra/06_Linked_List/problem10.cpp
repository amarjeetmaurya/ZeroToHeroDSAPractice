// 82. Remove Duplicates from Sorted List II

#include<iostream>
#include<stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper to print the list
void printList(ListNode *head) {
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ================================================================

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            bool duplicate = false;
            while (curr->next && curr->val == curr->next->val) {
                duplicate = true;
                curr = curr->next;
            }
            if (duplicate) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};


// ================================================================


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}
