class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> hi;

        for(int i=0;i<capital.size();i++)
        {
            hi.push_back({capital[i],profits[i]});
        }
        sort(hi.begin(),hi.end());
        int i=0;
        int iter=0;
        priority_queue<int> qu;
        while((!qu.empty() || i<capital.size()) && iter<k)
        {
            while(i<capital.size() && w>=hi[i].first)
            {
                qu.push(hi[i].second);
                i++;
            }
            if(qu.empty())
            {
                return w;
            }
            w+=qu.top();
            qu.pop();
            iter++;
            cout<<w<<"\n";
        }
        return w;
    }
};