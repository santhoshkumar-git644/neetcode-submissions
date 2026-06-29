class Solution {
public:
    double myPow(double x, int n) {
        double result=1;
        bool negative=false;
        if(n<0)
        {
            n=-1*n;
            negative=true;
        }
        for(int i=0;i<n;i++)
        {
            result=result*x;
        }
        if(negative)
        {
            result=1/result;
            return result;
        }
        return result;

    }
};
