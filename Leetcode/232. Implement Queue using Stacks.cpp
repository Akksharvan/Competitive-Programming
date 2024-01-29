class MyQueue {
public:
    stack<int> S1;
    stack<int> S2;

    MyQueue () { }
    
    void push (int x) {
        while (!S2.empty()) S1.push(S2.top()), S2.pop();
        S2.push(x); while (!S1.empty()) S2.push(S1.top()), S1.pop();

    }
    
    int pop () {
        int R = S2.top();
        S2.pop(); return R;
    }
    
    int peek () {
        return S2.top();
    }
    
    bool empty () {
        return S2.empty();
    }
};