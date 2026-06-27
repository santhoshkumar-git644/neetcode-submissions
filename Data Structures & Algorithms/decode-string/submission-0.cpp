class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                string store;
                while(st.top()!='[')
                {
                    store+=st.top();
                    st.pop();
                }
                reverse(store.begin(), store.end());
                st.pop();
                int num=0;
                int k=1;
                while(!st.empty() && st.top()-'0'<=9 && st.top()-'0'>=0)
                {
                    num = (st.top() - '0') * k + num;
                    k=k*10;
                    st.pop();
                }
                for(int i=0;i<num*store.size();i++)
                {
                    st.push(store[i%store.size()]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string result;
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};