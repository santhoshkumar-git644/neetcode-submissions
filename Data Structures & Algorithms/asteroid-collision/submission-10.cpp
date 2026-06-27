class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
            }
            else
            {
                if(asteroids[i]<0 && st.top()>0)
                {
                    if(abs(asteroids[i])==abs(st.top()))
                    {
                            st.pop();
                    }
                    else if(min(abs(asteroids[i]),abs(st.top()))==abs(asteroids[i]))
                    {
                        continue;
                    }
                    else
                    {
                        st.pop();
                        while(!st.empty() && abs(st.top())<abs(asteroids[i]) && st.top()*asteroids[i]<0)
                        {
                            st.pop();
                        }
                        if(st.empty() || st.top()*asteroids[i]>0)
                        {
                            st.push(asteroids[i]);
                        }
                        else
                        {
                            if(st.top()==(-1)*asteroids[i])
                            {
                                st.pop();
                            }
                        }
                    }
                }
                else
                {
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};