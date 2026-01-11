// 155. Min Stack

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

// =========================================

class MinStack {
public:
    MinStack() {}

    stack<pair<int, int>> st;

    void push(int val) {
        // int min;
        // if (st.empty()) {
        //     min = val;
        // } else {
        //     if (st.top().second > val) {
        //         min = val;
        //     } else {
        //         min = st.top().second;
        //     }
        // }
        int minVal = st.empty() ? val : min(val, st.top().second);
        st.push({val, minVal});
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    int top() {
        if (st.empty())
            throw underflow_error("Stack is empty");
        return st.top().first;
    }

    int getMin() {
        if (st.empty())
            throw underflow_error("Stack is empty");
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//  =========================================



int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top element: " << ms.top() << endl;       // Expected 2
    cout << "Current min: " << ms.getMin() << endl;    // Expected 2

    ms.pop(); // remove 2
    cout << "Top element after pop: " << ms.top() << endl;   // Expected 7
    cout << "Current min after pop: " << ms.getMin() << endl; // Expected 3

    ms.pop(); // remove 7
    cout << "Top element after another pop: " << ms.top() << endl;   // Expected 3
    cout << "Current min after another pop: " << ms.getMin() << endl; // Expected 3

    return 0;
}
