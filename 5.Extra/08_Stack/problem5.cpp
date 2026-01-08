// 232. Implement Queue using Stacks

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =========================================

class MyQueue {
public:
    MyQueue() {}
    stack<int> s1;
    stack<int> s2;
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s2.empty() && s1.empty()) 
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// =========================================

int main()
{
    
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek();  // return 1
    cout << myQueue.pop();   // return 1, queue is [2]
    cout << myQueue.empty(); // return false

    return 0;
}
