class Solution {
public:
    int getSum(int a, int b) {
        int carry=0,result=0;
        int present=1;
        bool negative=false;
        bool negative1=false;
        if(a<0 && b<0)
        {
            a=-1*a;
            b=-1*b;
            negative1=true;
        }
        
        while(a && b)
        {
            int first=a%2;
            int second=b%2;
            a=a/2;
            b=b/2;
            int sum=first^second^carry;
            if(carry && first || carry && second || first && second)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            result=result+present*sum;
            present=present*2;
        }
        while(b)
        {
            int second=b%2;
            b=b/2;
            int sum=second^carry;
            if(carry && second)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            result=result+present*sum;
            present=present*2;
        }
        while(a)
        {
            int first=a%2;
            a=a/2;
            int sum=first^carry;
            if(carry && first)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            result=result+present*sum;
            present=present*2;
        }
        cout<<result;
        result+=present*carry;
        if(negative1)
        {
            return -1*result;
        }
        return result;
    }
};
