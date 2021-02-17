#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if(x <= min) {
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        if (s.top() == min) {
            s.pop();
            min = s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
    
private:
    int min;
    stack<int> s;
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int res = obj->getMin();
    cout << "getMin: " << res << endl; 
    obj->pop();
    res = obj->top();
    cout << "top: " << res << endl;
    res = obj->getMin();
    cout << "getMin: " << res << endl; 
}