// 2130. Maximum Twin Sum of a Linked List

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
    int pairSum(ListNode* head) {
        int result = 0;
        ListNode *temp = head;
        int n = 0;
        while(temp) {
            temp=temp->next;
            n++;
        }
        // cout <<"length: " <<n;

        int half = n/2;
        stack<int> s;
        temp=head;
        while(temp) {
            if(half>0) {
                s.push(temp->val);
            } else {
                int sum = s.top()+temp->val;
                if(sum > result)
                    result=sum;
                s.pop();  
            }
            half--;
            temp=temp->next;
        }

        return result;
    }
};

// ================================================================


int main()
{
    cout << "Woopsy doopsy!!" << endl;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    // sol.middleNode(head->next);

    cout << "result -> ";
    // printList(sol.pairSum(head));
    cout << "-> " << sol.pairSum(head);

    return 0;
}