class Solution {
public:
    
    string helper( string word ) {
        
        vector < char > vec(26, 0);
        char curr = 'a';
        
        for ( auto i : word ) {
            
            if ( !vec[i - 'a']) {
                
                vec[i - 'a'] = curr;
                curr += 1;
                
            }
            
        }

        
        for ( int i = 0 ; i < word.size() ; i++ ) {
            
            word[i] = vec[word[i] - 'a'];
            
        }
        
        return word;
        
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector < string > ans;
        
        string str = helper(pattern);
        
        for ( auto word : words ) {
            
            if ( helper(word) == str ) {
                
                ans.push_back(word);
                
            }
            
        }
            
        return ans;
        
    }
};
