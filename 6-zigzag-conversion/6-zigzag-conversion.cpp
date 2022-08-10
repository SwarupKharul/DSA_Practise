class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        
        string ans[numRows] ;
        int down = 1; 
        int row = 0;
        
        
        for(auto &it: s){
            ans[row].push_back(it);
            if(row==numRows-1) down=-1;
            else if(row==0) down=1;
            row+=down;
        }
        
        s.clear();
        
        for(int i=0; i<numRows; ++i)
            s.append(ans[i]);
        
        return s;
    }
};