#include <bits/stdc++.h>
using namespace std;

struct MyStack {

    stack<int> ms; // main Stack
    stack<int> as; // auxiliary stack

// We only push in as if element is min than ms.top()

    void push(int x) {

        if (ms.empty() ) {
            ms.push(x); as.push(x); return;
        }

        ms.push(x);

        if (as.top() >= ms.top())
            as.push(x);
    }

    void pop() {

        if (as.top() == ms.top())
            as.pop();
        ms.pop();

    }

    int top() {
        return ms.top();
    }

    int getMin() {
        return as.top();
    }
};

// TC - O(1)

int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();

    cout << " Minimum Element from Stack: " << s.getMin();

    return 0;
}
