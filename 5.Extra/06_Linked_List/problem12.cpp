// 61. Rotate List


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
    ListNode* rotateRight(ListNode* head, int k) {
        // 2nd submission
        if(!head || !head->next || k == 0) return head;

        ListNode *temp = head;
        int len = 1;
        while(temp->next) {
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;

        temp->next = head;
        temp=head;
        int pos = len - k;
        while(temp && pos>1) {
            temp=temp->next;
            pos--;
        }
        head = temp->next;
        temp->next = nullptr;

        return head;
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
    head = sol.rotateRight(head, 2);

    cout << "List after rotating right by 2 positions: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}
