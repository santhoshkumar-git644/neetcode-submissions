class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        vector<int> s1;
        vector<int> s2;
        for(int i=0;i<s.size();i++)
        {
            s1.push_back(s[i]-'0');
            s2.push_back(t[i]-'0');
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                return false; 
            }
        }
        return true;
    }
};
