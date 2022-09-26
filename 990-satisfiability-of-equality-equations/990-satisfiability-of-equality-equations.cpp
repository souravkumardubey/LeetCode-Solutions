class Solution {
    
    vector < int > uni;
    
    int find(int node) {
        
        if ( uni[node] != node ) {
            
            uni[node] = find(uni[node]);
            
        }
        
        return uni[node];
        
    }
    
public:
    bool equationsPossible(vector<string>& eq) {
        
        uni.resize(26);
        
        for ( int i = 0 ; i < 26 ; i++ ) {
            
            uni[i] = i;
            
        }
        
        for ( auto i : eq ) {
            
            if ( i[1] == '=' ) {
                
                uni[find(i[0]-'a')] = find(i[3]-'a');
                
            }
            
        }
        
        for ( auto i : eq ) {
            
            if ( i[1] == '!' ) {
                
                if ( find(i[0]-'a') == find(i[3]-'a') ) {
                    
                    return false;
                    
                }
                
            }
            
        }
        
        return true;
        
    }
};