// 19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;

        ListNode *temp = head;
        int len = 0;
        while(temp) {
            cout << temp->val;
            len++;
            temp=temp->next;
        }
        cout <<endl;
        // cout <<"length: " <<len;
        int toRemove = len-n+1;
        if(toRemove==1) return head->next;
        temp = head;
        while(toRemove > 2) {
            temp=temp->next;
            toRemove--;
        }

        ListNode *remove = temp->next;
        temp->next = (remove->next)?remove->next:nullptr;
        delete remove;

        return head;
    }
};
// ================================================================


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int n = 2; 
    head = sol.removeNthFromEnd(head, n);

    cout << "\nList after removing " << n << "th node from end: ";
    printList(head);

    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}
