class Solution {
    
    int n;
    
    vector < int > vis;

    map < int , vector < int > >adj;
    
public:
    
    bool dfs( int child  , int parent ) {
        
        if ( count(vis.begin(),vis.end(),child) ) return true;
        vis.push_back(child);
        
        for ( auto i : adj[child] ) {
            
            if ( i == parent ) continue;

            if ( dfs(i, child) ) return true;
            
        }
        
        return false;
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        n = edges.size();
        // vis.resize(1005,0);
        
        
        for ( int i = 0; i < n ; i++ ) {
            
            adj[--edges[i][0]].push_back(--edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            if ( dfs( edges[i][0] , -1 ) ) {
                
                return {edges[i][0]+1,edges[i][1]+1};
                
            }
            
            vis.clear();
            
        }

        return {};
        
    }
};
