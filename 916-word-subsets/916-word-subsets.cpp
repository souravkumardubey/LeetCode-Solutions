class Solution {
    
    vector < int > helper(string word) {
        
        vector < int > fre(26);
        
        for ( char c : word ) {
            
            fre[c - 'a']++;
            
        }
        
        return fre;
        
    }
    
    
public:
    
    vector < string > wordSubsets( vector < string >& A, vector < string >& B) {
        
        vector < int > cnt(26), tmp(26);
        
        for ( string b : B ) {
            
            tmp = helper(b);
            
            for ( int i = 0; i < 26; i++ ) {
                
                cnt[i] = max(cnt[i], tmp[i]);
                
            }
                
        }
        
        vector < string > ans;
        
        for ( string a : A ) {
            
            tmp = helper(a);
            int flag = 0;
            
            for ( int i = 0; i < 26; i++ ) {
                
                if ( tmp[i] < cnt[i] ) {
                    
                    flag = 1;
                    break;
                    
                } 
                
            }
                
            if ( !flag ) ans.push_back(a);
            
        }
        
        return ans;
        
    }

};