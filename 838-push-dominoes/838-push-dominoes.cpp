class Solution {
public:
    string pushDominoes(string dominoes) {
        
        string ans = "";
        dominoes = 'L' + dominoes + 'R';
        
        int i = 1, last = 0;
        int n = dominoes.size();
        
        while ( i < n ) {
            
            if ( dominoes[i] == '.' ) {
                
                i += 1;
                continue;
                
            }
            
            if ( last != 0 ) {
                
                ans += dominoes[last];
                
            }
            
            if ( dominoes[i] == dominoes[last] ) {
                
                for ( int j = last + 1; j < i; j++ ) {
                    
                    ans += dominoes[i];
                    
                }
                
                last = i;
                
            }
            else if ( dominoes[last] == 'L' && dominoes[i] == 'R' ) {
                
                for ( int j = last + 1; j < i; j++ ) {
                    
                    ans += '.';
                    
                }
                
                last = i;
                
            }
            else {
                
                int dis = i - last - 1;
                
                for ( int j = 0; j < dis / 2; j++ ) {
                    
                    ans += 'R';
                    
                }
                
                if ( dis & 1 ) ans += '.';
                
                for ( int j = 0; j < dis / 2; j++ ) {
                    
                    ans += 'L';
                    
                }
                
                last = i;
                
            }
            
            i += 1;
            
        }
        
        return ans;
        
    }
};