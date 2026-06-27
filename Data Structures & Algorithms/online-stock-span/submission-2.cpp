class StockSpanner {
    private:
    stack<int> st;
    int index=0;
    vector<int> arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()]<=price)
        {
            st.pop();
        }
        if(st.empty())
        {
            st.push(index);
            index++;
            return index;
        }
        else
        {
            int var=index-st.top();
            cout<<"hi";
            st.push(index);
            index++;
            return var;
        }
        
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */