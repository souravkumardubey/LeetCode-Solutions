class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map < int , int > fre , seq;
        
        for ( auto i : nums ) fre[i]++;

        for ( auto i : nums ) {
            
            if ( fre[i] == 0 ) continue;
			
            if (seq[i - 1] > 0 ) {
                
                fre[i] -= 1;
                seq[i - 1] -= 1;
                seq[i] += 1;
                
            }
            else {
                
                if ( fre[i + 1] == 0 || fre[i + 2] == 0 ) return false;
                
                fre[i] -= 1;
                fre[i + 1] -= 1;
                fre[i + 2] -= 1;
                seq[i + 2] += 1;
                
            }
            
        }
        
        return true;        
    }
};