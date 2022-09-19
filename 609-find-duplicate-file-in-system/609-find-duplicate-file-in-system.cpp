class Solution {
    
public:
    
    vector < vector < string > > findDuplicate ( vector < string >& paths ) {
        
        unordered_map < string , vector < string > > mp;
        
        vector < vector < string > > ans;
        

        for ( string &i : paths ) {
            
            string path = "", file_name = "", content = "";
            
            int flag = 1;
            
            for ( char &j : i ) {
                
                if ( j == ' ' ) {
                    
                    flag = 2;
                    continue;
                    
                }

                if ( j == '(' ) {
                    
                    flag = 3;
                    continue;
                    
                }
                
                if ( j == ')' ) {
                    
                    mp[content].emplace_back( path + '/' + file_name );
                    
                    file_name = "";
                    
                    content = "";
                    continue;
                    
                }


                if ( flag == 1 ) path += j;
                else if ( flag == 2 ) {
                    
                    file_name += j;
                    
                }
                else if ( flag == 3 ) {
                    
                    content += j;
                    
                }   
                
            }
            
        }

        for ( auto &i : mp ) {
            
            if ( i.second.size() > 1 ) {
                
                ans.push_back(i.second);
                
            }
            
        }
        
        return ans;
    }
    
};