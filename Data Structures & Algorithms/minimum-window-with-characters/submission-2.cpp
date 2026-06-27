class Solution {
public:
    bool matched(unordered_map<int,int>& mp1,unordered_map<int,int>& mp2)
    {
        for(auto const& [key, val] : mp1)
        {
            if(mp2.count(key) && mp2.at(key) >= val)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        
        if(t.size()>s.size())
        {
            return "";
        }
        
        for(int i=0;i<t.size();i++)
        {
            if(mp1.find((int)t[i])==mp1.end())
            {
                mp1.insert({(int)t[i],1});
            }
            else
            {
                mp1[(int)t[i]]++;
            }
            if(mp2.find((int)s[i])==mp2.end())
            {
                mp2.insert({(int)s[i],1});
            }
            else
            {
                mp2[(int)s[i]]++;
            }
        }
        if(s.size()==t.size())
        {
            if(matched(mp1,mp2))
            {
                return s;
            }
            else
            {
                return "";
            }
        }
        int left=0;
        int right=t.size()-1;
        int len=INT_MAX;
        string result="";
        while(left!=s.size())
        {
            if(right==s.size()-1)
            {
                if(matched(mp1,mp2))
                {
                    len=min(len,right-left+1);
                    if(len!=result.size())
                    {
                        result=s.substr(left,right-left+1);
                    }
                }
                mp2[(int)s[left]]--;
                left++;
                continue;
            }
            if(matched(mp1,mp2))
            {
                cout<<right<<"\n";
                len=min(len,right-left+1);
                if(len!=result.size())
                {
                    cout<<left<<"/0"<<right<<"\n";
                    result=s.substr(left,right-left+1);
                }
                mp2[(int)s[left]]--;
                left++;
            }
            else
            {
                right++;
                if(mp2.find((int)s[right])==mp2.end())
                {
                    mp2.insert({(int)s[right],1});
                }
                else
                {
                    mp2[(int)s[right]]++;
                }
                
            }
        }
        return result;
    }
};