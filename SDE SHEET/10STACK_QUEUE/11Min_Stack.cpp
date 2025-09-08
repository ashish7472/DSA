class MinStack {
private:
    stack<int> st;
    stack<int> minSt; // stack to keep track of minimum elements

public:
    MinStack() {
        // Initialize the minimum stack with INT_MAX
        minSt.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        // Update the minimum stack
        if (val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        // If the element being popped is the minimum, update the minimum stack
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};