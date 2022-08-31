class Solution {
    
    bool dfs( int i , int j , int start , int end , int n , int m , vector < vector < char > >& grid , vector < vector < bool > >& vis ) {
                
//         if the cell is already visited then that mean there's a cycle.
        if ( vis[i][j] ) return true;
        
        vis[i][j] = true;
        
//         the next index shouldn't be equal to the prev ones
        if ( i + 1 != start and i + 1 < n and grid[i+1][j] == grid[i][j] ) {
            
            if ( dfs(i + 1 , j , i , j , n , m , grid , vis) ) return true;
            
        }
        
        if ( i - 1 != start and i - 1 >= 0 and grid[i-1][j] == grid[i][j] ) {
            
            if ( dfs(i - 1 , j , i , j , n , m, grid , vis) ) return true;
            
        }
        
        if ( j + 1 != end and j + 1 < m and grid[i][j+1] == grid[i][j] ) {
            
            if ( dfs(i , j + 1 , i , j , n , m , grid , vis) ) return true;
            
        }
        
        if ( j - 1 != end and j - 1 >= 0 and grid[i][j-1] == grid[i][j] ) {
            
            if ( dfs(i , j - 1 , i , j , n , m , grid , vis) ) return true;
            
        }

        return false;
        
    }
    
public:
    
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        
        vector < vector < bool > > vis( n , vector < bool > (m , false ) );
        
        for ( int i = 0 ; i < n ; i++ ) {
            
            for ( int j = 0 ; j < m ; j++ ) {
                
                if ( !vis[i][j] ) {
                    
                    if ( dfs(i , j ,-1, -1 , n , m , grid , vis) ) {
                        
                        return true;
                        
                    }
                    
                }
                
            }
            
        }
        
        return false;
        
    }
};