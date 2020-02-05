
#include<stack>
#include <climits>

struct entry {
    int data;
    int min = INT_MAX;
};

class MinStack {
public:
    /** initialize your data structure here. */
    stack<entry> s;

    MinStack() {}
    
    void push(int x) {
        entry e;
        e.data = x;
        if (s.empty()) {
            e.min = x;
        } else if (x < s.top().min) {
            e.min = x;
        } else {
            e.min = s.top().min;
        }  
        s.push(e);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        if (s.empty()) return -1;
        return s.top().data;
    }
    
    int getMin() {
        if (s.empty()) return -1;
        return s.top().min;
    }
    
    
};


