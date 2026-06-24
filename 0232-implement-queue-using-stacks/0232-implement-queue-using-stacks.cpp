class MyQueue {
public:
    stack<int>ans;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) {
       if(ans.size()==0){
        ans.push(x);
        return ;
       } 
       else{
        while(ans.size()>0){
            helper.push(ans.top());
            ans.pop();
        }
        ans.push(x);
        while(helper.size()>0){
            ans.push(helper.top());
            helper.pop();
        }  
        return;
       }
    }
    
    int pop() {
        int x=ans.top();
        ans.pop();
        return x;
    }
    
    int peek() {
        int x= ans.top();
        return x;
    }
    
    bool empty() {
        if(ans.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */