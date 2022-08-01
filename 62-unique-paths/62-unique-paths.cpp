class Solution {
public:
    
    int backTrack(int i , int j , int m , int n , vector < vector < int > > &dp) {
        
        if ( i >= m || j >= n ) return 0;
        
        if ( i == m - 1 && j == n - 1 ) return 1;
        
        if ( dp[i][j] ) return dp[i][j];
        
        return dp[i][j] = backTrack(i+1,j,m,n,dp) + backTrack(i,j+1,m,n,dp);
        
        
    }
    
    int uniquePaths(int m, int n) {
        
        vector < vector < int > > dp( 101 , vector < int > (101 , 0) );
        return backTrack(0,0,m,n,dp);
        
        // return vec[0][0];
        
    }
};