// 901. Online Stock Span
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =========================================

class StockSpanner
{
public:
    StockSpanner() {}
    stack<pair<int, int>> s;

    int next(int price)
    {
        int span = 1;
        while (!s.empty() && s.top().first <= price)
        {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

// =========================================

int main()
{
    StockSpanner stockSpanner;

    cout << stockSpanner.next(100) << endl; // 1
    cout << stockSpanner.next(80) << endl;  // 1
    cout << stockSpanner.next(60) << endl;  // 1
    cout << stockSpanner.next(70) << endl;  // 2
    cout << stockSpanner.next(60) << endl;  // 1
    cout << stockSpanner.next(75) << endl;  // 4
    cout << stockSpanner.next(85) << endl;  // 6

    return 0;
}
