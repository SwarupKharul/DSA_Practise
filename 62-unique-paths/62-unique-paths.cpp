class Solution {
public:
   vector<vector<int> > db;
    int solve(int m, int n, int i, int j){
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0)  return 0;
        if(db[i][j]) return db[i][j];
        return db[i][j] = solve(m, n, i-1, j) + solve(m, n, i, j-1);
    }
    
    int uniquePaths(int m, int n) {
        db.resize(m, vector<int>(n,0));
        return solve(m, n, m-1, n-1);
    }
};