class Solution {
    
    void dfs( int i , int j , int n , int m , map < pair < int , int > , int >& vis , int prev , vector < vector < int > >& heights ) {
        
        if ( vis[{i,j}] or i < 0 or j < 0 or i == n or j == m or heights[i][j] < prev ) {
            
            return;
            
        }
        
        vis[{i,j}] = 1;
        
        dfs( i + 1 , j , n , m , vis , heights[i][j] , heights );
        dfs( i - 1 , j , n , m , vis , heights[i][j] , heights );
        dfs( i , j + 1 , n , m , vis , heights[i][j] , heights );
        dfs( i , j - 1 , n , m , vis , heights[i][j] , heights );
        
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size() , m = heights[0].size();
        
        map < pair < int , int > , int > pacific , atlantic;
        
        for ( int i = 0 ; i < m ; i++ ) {
            
            dfs( 0 , i , n , m , pacific , heights[0][i] , heights );
            dfs( n - 1 , i , n , m , atlantic , heights[n-1][i] , heights );
            
        }
        
        for ( int i = 0 ; i < n ; i++ ) {
            
            dfs( i , 0 , n , m , pacific , heights[i][0] , heights );
            dfs( i , m - 1 , n , m , atlantic , heights[i][m-1] , heights );
            
        }
        
        vector < vector < int > > ans;
        
        for ( int i = 0 ; i < n ; i++ ) {
            
            for ( int j = 0 ; j < m ; j++ ) {
                
                if ( pacific[{i,j}] and atlantic[{i,j}] ) {
                    
                    vector < int > vec;
                    vec.push_back(i);
                    vec.push_back(j);
                    ans.push_back(vec);
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};