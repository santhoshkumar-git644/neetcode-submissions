class Solution {
public:
    int reverse(int x) {
        long long int result=0;
        bool negative=false;
        
        if(x<0)
        {
            x=abs(x);
            negative=true;
        }
        while(x)
        {
            int remainder=x%10;
            x=x/10;
            result=result*10+remainder;
        }
        if(result>2147483647 || result<-2147483648)
        {
            return 0;
        }
        int final=result;
        if(negative)
        {
            return -1*final;
        }
        return final;
    }
};
