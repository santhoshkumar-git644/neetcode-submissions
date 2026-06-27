class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(int i=0;i<trips.size();i++)
        {
            int temp=trips[i][0];
            trips[i][0]=trips[i][1];
            trips[i][1]=temp;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
        sort(trips.begin(),trips.end());
        int time=trips[0][0];
        int num=0;
        int i=0;
        while(i<trips.size() || !qu.empty())
        {
            while(i<trips.size() && time>=trips[i][0])
            {
                num+=trips[i][1];
                qu.push({trips[i][2],trips[i][1]});
                i++;
            }
            if(qu.empty())
            {
                time=trips[i][0];
                continue;
            }
            while(!qu.empty() && time>=qu.top().first)
            {
                num-=qu.top().second;
                qu.pop();
            }
            if(num>capacity)
            {
                return false;
            }
            time++;
            cout<<time;
        }
        return true;
    }
};