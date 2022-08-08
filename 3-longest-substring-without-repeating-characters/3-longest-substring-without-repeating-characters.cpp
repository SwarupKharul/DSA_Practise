class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(!s.size())
            return 0;
        
        unordered_map<char,bool> mp;
        
        int mx = 1;
        int j = 0, i=0;
        for(i = 0; i<j+1; ++i){
            while(j<s.size()){
                cout<<j<<" ";
                if(mp.count(s[j])){
                    mx = max(mx, j-i);
                    break;
                }
                else
                    mp[s[j]] = true;
                ++j;
            }
            if(j==s.size()){
                mx = max(mx, j-i);
                break;
            }
            mp.erase(s[i]);
        }
        return max(mx, j-i);
    }
};