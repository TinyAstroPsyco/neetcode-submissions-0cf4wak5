class MinStack {
    int t = -1;
    int arr[10000];
    int arr2[10000]; 
    int min_val = INT_MAX;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        arr[++t] = val;
        min_val = min(min_val, val);
        arr2[t] = min_val;
    }
    
    void pop() {
        t--;
        if(t  == -1) min_val = INT_MAX;
        else {
            min_val = arr2[t];}
        
    }
    
    int top() {
        return arr[t];
    }
    
    int getMin() {
        return arr2[t];
    }
};
