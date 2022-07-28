class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if ( s == t ) return true;
        
        if ( s.size() != t.size() ) return false;
        
        vector < int > charCnt(27 , 0);
        
        for ( int i = 0 ; i < s.size() ; i++ ) {
            
            charCnt[s[i]-'a']++;
            charCnt[t[i]-'a']--;
            
        }
        
        for ( int i = 0 ; i < 27 ; i++ ) {
            
            if ( charCnt[i] != 0 ) return false;
            
        }
        
        return true;
        
    }
    
};