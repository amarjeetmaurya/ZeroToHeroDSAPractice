// 86. Partition List


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
    ListNode* partition(ListNode* head, int x) {

        ListNode *temp = head;
        ListNode *greater = new ListNode(8);
        ListNode *add = greater;
        ListNode *lesser = new ListNode(8);
        ListNode *result = lesser;
        while(temp) {
            if(temp->val < x) {
                lesser->next = temp;
                lesser=lesser->next;
            } else {
                greater->next = temp;
                greater=greater->next;
            }
            temp=temp->next; 
        }
        greater->next = nullptr;
        lesser->next = (add->next)?add->next:nullptr;

      return result->next;
    }
};

// ================================================================


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);
    Solution sol;
    head = sol.partition(head, 3);
    cout << "List after partitioning around 3: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}
