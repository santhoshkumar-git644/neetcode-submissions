class Solution {
public:
    int tribonacci(int n) {
        int first=0;
        int second=1;
        int third=1;
       
        if(n==3)
        {
            return 2;
        }
        if(n==1||n==2)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        for(int i=0;i<=n-3;i++)
        {
            int present=first+second+third;
            first=second;
            second=third;
            third=present;
        }
        return third;
    }
};