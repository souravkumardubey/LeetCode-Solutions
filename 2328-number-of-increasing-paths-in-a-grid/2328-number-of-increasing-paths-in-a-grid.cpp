class Solution {
public:
    
    pair<int,int>p[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}; 
    const int mod = 1e9 +7; 
    int n, m; 
     
    long long solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) { 
        if(dp[i][j] != -1) return dp[i][j]; 
        long long count = 0; 
        for(auto [x,y]: p) { 
            x += i, y += j; 
            if(x < 0 || y < 0 || x >= n || y >= m || grid[i][j] >= grid[x][y] ) continue; 
            count += (1 + solve(x, y,grid,dp)) %mod; 
            count %= mod; 
        } 
        return dp[i][j] = count; 
    } 
     
     
    int countPaths(vector<vector<int>>& grid) { 
        n= grid.size(), m= grid[0].size(); 
         
        vector<vector<int>>dp( n, vector<int>(m,-1)); 
        long long ans=0; 
        for( int i=0; i<n ;i++){ 
            for( int j=0; j<m ;j++){ 
                ans+=solve(i,j,grid,dp)%mod + 1; 
                ans %=mod; 
            } 
        } 
        return ans%mod;
    }
};