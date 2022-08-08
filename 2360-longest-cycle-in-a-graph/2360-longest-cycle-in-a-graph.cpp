class Solution {
    
     int maxDistance = -1;
    
    void dfs ( vector < vector < int > >& graph , vector < int > &vis , int node , int distance , map < int, int >&mp ) {
        
        vis[node] = 1;

        mp[node] = distance;

        for ( auto x : graph[node] ) {

            if ( !vis[x] ) {

                dfs(graph , vis , x , distance + 1 , mp);

            }
            else if ( mp.count(x) ) {

                int diff = distance - mp[x] + 1;
                maxDistance = max(maxDistance, distance - mp[x] + 1);

            }

        }
        
    }

    public :
    
    int longestCycle( vector < int >& edges ) {
        
        int n = edges.size();
        vector < vector < int > > adj(n);
        
        for (int i = 0 ; i < adj.size() ; i++) {
            
            if ( edges[i] != -1 ) {
                
                adj[i].push_back(edges[i]);
                
            }
            
        }
        
        vector < int > vis(n , 0);
        
        for ( int i = 0 ; i < n ; i++ ) {
            
            if ( !vis[i] ) {
                
                map < int , int > mp;
                
                dfs(adj , vis, i , 0 , mp);
                
            }
            
        }
        
        return maxDistance;
        
	}
    
};
