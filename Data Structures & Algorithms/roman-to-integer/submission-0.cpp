class Solution {
public:
    int romanToInt(string s) {
        int similar_value=convert(s[0]);
        int similar_char=s[0];
        int total_value=0;
        int i=1;
        while(i<s.size())
        {
            while(i<s.size() && s[i]==similar_char)
            {
                similar_value+=convert(s[i]);
                i++;
            }
            if(i<s.size() && convert(similar_char)<convert(s[i]))
            {
                total_value-=similar_value;
            }
            else
            {   
                total_value+=similar_value;
            }
            similar_value=0;
            similar_char=s[i];
        }
        if(similar_value!=0)
        {
            total_value+=similar_value;
        }
        return total_value;
    }
private:
    int convert(char a)
    {
        if(a=='I')
        {
            return 1;
        }
        if(a=='V')
        {
            return 5;
        }
        if(a=='X')
        {
            return 10;
        }
        if(a=='L')
        {
            return 50;
        }
        if(a=='C')
        {
            return 100;
        }
        if(a=='D')
        {
            return 500;
        }
        if(a=='M')
        {
            return 1000;
        }
    }
};