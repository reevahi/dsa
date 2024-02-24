/*
@author github.com/iitzmahi
*/
class MinStack {
private:
    int min = INT_MAX;

private:
    stack<pair<int, int>> s;

public:
    MinStack() {}

    void push(int val) {
        if (val < min) {
            s.push({val, val});
            min = val;
        } else {
            s.push({val, min});
        }
    }

    void pop() {
        s.pop();
        if (s.empty()) {
            min = INT_MAX;
        } else {
            min = s.top().second;
        }
    }

    int top() { return s.top().first; }

    int getMin() { return s.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */