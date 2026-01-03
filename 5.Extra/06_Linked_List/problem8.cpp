// 445. Add Two Numbers II

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        // if(!l)

        int length1 = 0;
        int length2 = 0;
        stack<int> s1;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
            length1++;
        }
        stack<int> s2;
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
            length2++;
        }

        // cout << "length1: " << length1 << endl;
        // cout << "length2: " << length2 << endl;
        int min = (length1 < length2) ? length1 : length2;
        // cout << "min: " << min << endl;
        int whichOne = (length1 < length2) ? 1 : 2;

        ListNode* result = new ListNode(5);
        int remain = 0;
        stack<int> s3;
        while (min) {
            int sum = s1.top() + s2.top() + remain;
            // cout << " " << sum;
            remain = sum / 10;
            // cout << " " << sum % 10;
            s3.push(sum % 10);
            s1.pop();
            s2.pop();
            min--;
        }

        if (whichOne == 1) {
            while (!s2.empty()) {
                s3.push((s2.top() + remain)%10);
                remain = (s2.top() + remain) / 10;
                s2.pop();
            }
        } else {
            while (!s1.empty()) {
                s3.push((s1.top() + remain)%10);
                remain = (s1.top() + remain) / 10;
                s1.pop();
            }
        }
        if (remain) {
            s3.push(remain);
        }

        ListNode* rtemp = result;
        while (!s3.empty()) {
            // cout << s3.top() << " ";
            ListNode* temp = new ListNode(s3.top());
            rtemp->next = temp;
            rtemp = rtemp->next;
            s3.pop();
        }

        return result->next;
    }
};

// ================================================================


int main()
{
    cout << "Woopsy doopsy!!" << endl;
    ListNode *head = new ListNode(7);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);

    ListNode *head1 = new ListNode(5);
    head1->next = new ListNode(6);
    head1->next->next = new ListNode(4);

    cout << "list1: ";
    printList(head);
    cout << "list2: ";
    printList(head1);

    Solution sol;

    cout << "result -> ";
    ListNode *result = sol.addTwoNumbers(head, head1);
    printList(result);

    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    while (head1) {
        ListNode *temp = head1;
        head1 = head1->next;
        delete temp;
    }
    
    return 0;
}