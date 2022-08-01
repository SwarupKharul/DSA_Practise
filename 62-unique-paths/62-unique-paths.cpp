class Solution {
public:
   vector<vector<int> > db;
    int solve(int m, int n){
        if(m==0 && n==0)    return 1;
        if(n<0 || m<0)  return 0;
        if(db[m][n]) return db[m][n];
        return db[m][n] = solve(m-1, n) + solve(m, n-1);
    }
    
    int uniquePaths(int m, int n) {
        db.resize(m, vector<int>(n,0));
        return solve(m-1, n-1);
    }
};