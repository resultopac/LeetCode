#include <stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {
        
    }

    stack<int> s;

    void push(int x) {
        stack<int> temp ;
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int d = s.top();
        s.pop();
        return d;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};