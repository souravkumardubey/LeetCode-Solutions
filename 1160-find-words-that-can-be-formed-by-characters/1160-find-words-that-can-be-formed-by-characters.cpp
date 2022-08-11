class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector < int > charsFreq(26, 0);
        
        for ( auto ch : chars ) {
            
            charsFreq[ch - 'a'] += 1;
            
        } 
        
        int cnt = 0;
        
        for ( auto s : words ) {

            bool flag = true;
            
            vector < int > sFreq(26, 0);

            for ( auto ch : s ) {
                
                sFreq[ch - 'a'] += 1;
                
                if ( sFreq[ch - 'a'] > charsFreq[ch - 'a'] ) {
                    
                    flag = false;
                    break;
                    
                }
                
            }

            if ( flag ) {
                
                cnt += s.size();
                
            }
            
        }
        
        return cnt;
        
    }
    
};