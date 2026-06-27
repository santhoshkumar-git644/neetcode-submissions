class Solution {
public:
    bool recur(vector<int>& matchsticks,int first,int second,int third,int four,int sum,int start)
    {
        if(first>sum/4 || second>sum/4 || third>sum/4 || four>sum/4)
        {
            return false;
        }
        if(first==sum/4 && second==sum/4 && third==sum/4 && four==sum/4)
        {
            return true;
        }
        if(start>=matchsticks.size())
        {
            return false;
        }
        if(recur(matchsticks,first+matchsticks[start],second,third,four,sum,start+1) ||
        recur(matchsticks,first,second+matchsticks[start],third,four,sum,start+1) || 
        recur(matchsticks,first,second,third+matchsticks[start],four,sum,start+1) ||
        recur(matchsticks,first,second,third,four+matchsticks[start],sum,start+1))
        {
            return true;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int first=0,second=0,third=0,four=0;
        int sum=0;
        for(int i=0;i<matchsticks.size();i++)
        {
            sum+=matchsticks[i];
        }
        for(int i=0;i<matchsticks.size();i++)
        {
            if(matchsticks[i]>sum/4)
            {
                return false;
            }
        }
        if(sum%4!=0)
        {
            return false;
        }
        return recur(matchsticks,first,second,third,four,sum,0);
    }
};