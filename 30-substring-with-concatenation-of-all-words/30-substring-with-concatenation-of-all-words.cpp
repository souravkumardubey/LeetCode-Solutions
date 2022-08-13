class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.size() , m = words.size() , sz = words[0].size();
        
        int totalLen = m * sz;
        
        if ( totalLen > n ) return {};
        
        unordered_map < string , int > mp;
        vector < int > indices;
        
        for ( auto i : words ) mp[i] += 1;
        
        for ( int i = 0 ; i <= n - totalLen ; i++ ) {
            
            unordered_map < string , int > mp2 = mp;
            
            int j;
            
            for ( j = 0 ; j < n ; j++ ) {
                
                string str = s.substr( i + j * sz , sz );
                
                if ( mp2[str] == 0 ) break;
                else mp2[str] -= 1;
                
            }
            
            if ( j == m ) indices.push_back(i);
            
        }
        
        return indices;
        
    }
};