class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int first=0;
        while(first!=a.size() && first!=b.size())
        {
            int one=a[first]-'0';
            int two=b[first]-'0';
            result+=(one^two^carry+'0');
            if(one && two || carry && one || carry && two)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            first++;
        }
        while(first<a.size())
        {
            int one=a[first]-'0';
            result+=(one^carry+'0');
            if(carry && one)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            first++;
        }
        while(first<b.size())
        {
            int two=b[first]-'0';
            result+=(two^carry+'0');
            if(carry && two)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            first++;
        }
        if(carry==1)
        {
            result+='1';
        }
        reverse(result.begin(),result.end());
        return result;
    }
};