#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
    stack<int> stackNewestOnTop;
    stack<int> stackOldestOnTop;
public:
    void enqueue(int value) { // Push onto newest stack
        stackNewestOnTop.push(value);
    }

    int peek() {
        prepOld();
        return stackOldestOnTop.top();
    }

    void dequeue() {

        prepOld();
        return stackOldestOnTop.pop();

    }

    void prepOld() {
        if (stackOldestOnTop.empty())
            while (!stackNewestOnTop.empty()) {
                int temp = stackNewestOnTop.top();
                stackNewestOnTop.pop();
                stackOldestOnTop.push(temp);
            }
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            q1.enqueue(x);
        }
        else if (type == 2) {
            q1.dequeue();
        }
        else cout << q1.peek() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
