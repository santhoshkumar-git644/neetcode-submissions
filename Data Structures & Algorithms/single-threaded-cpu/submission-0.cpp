class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int time=0;
        vector<vector<int>> arr;

for(int i = 0; i < tasks.size(); i++)
{
    arr.push_back({tasks[i][0], tasks[i][1], i});
}
        sort(arr.begin(),arr.end());
        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> qu;
        vector<int> order;
        int i=0;
        while(!qu.empty() || i<arr.size())
        {
            while(i<arr.size() && time>=arr[i][0])
            {
                qu.push({arr[i][1],arr[i][2]});
                i++;
            }
            if(qu.empty())
            {
                time=arr[i][0];
                continue;
            }
            time+=qu.top().first;
            order.push_back(qu.top().second);
            qu.pop();
        }
        return order;
    }
};