class FreqStack {
public:
    vector<stack<int>> mp;
    unordered_map<int,int> freq;
    int size=0;
    FreqStack() {
    }
    
    void push(int val) {
        if(freq.find(val)==freq.end())
        {
            freq.insert({val,1});
        }
        else
        {
            freq[val]++;
        }
        if(freq[val]>mp.size())
        {
            stack<int> st;
            st.push(val);
            mp.push_back(st);
            size++;
        }
        else if(mp[freq[val]-1].empty())
        {
            mp[freq[val]-1].push(val);
            size++;
        }
        else
        {
            mp[freq[val]-1].push(val);
        }
        cout<<"hi";
        return;
    }
    
    int pop() {
        int val=mp[size-1].top();
        mp[size-1].pop();
        freq[val]--;
        if(mp[size-1].empty())
        {
            size--;
        }
        cout<<"hi";
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */