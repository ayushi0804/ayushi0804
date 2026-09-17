class StockSpanner {
public:
    vector<int> p; 
    vector<int> ans; 
    stack<int> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        p.push_back(price);
        int i = p.size() - 1;
        while(s.size() > 0 && p[s.top()] <= p[i]) s.pop();
        if(s.empty()) 
            ans.push_back(i+1);
        else 
            ans.push_back(i - s.top());
        s.push(i);
        
        return ans[i];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */