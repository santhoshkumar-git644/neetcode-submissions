class FreqStack {
public:
    vector<stack<int>> mp;
    unordered_map<int,int> freq;
    int size = 0;

    FreqStack() {
        mp.push_back(stack<int>()); // dummy at index 0, so freq 1 → mp[1]
    }
    
    void push(int val) {
        freq[val]++;  // cleaner: default-initializes to 0
        
        if (freq[val] > size) {
            stack<int> st;
            st.push(val);
            mp.push_back(st);
            size++;
        } else {
            mp[freq[val]].push(val);
        }
    }
    
    int pop() {
        int val = mp[size].top();
        mp[size].pop();
        if (mp[size].empty()) {
            mp.pop_back();  // also shrink the vector
            size--;
        }
        freq[val]--;
        return val;
    }
};