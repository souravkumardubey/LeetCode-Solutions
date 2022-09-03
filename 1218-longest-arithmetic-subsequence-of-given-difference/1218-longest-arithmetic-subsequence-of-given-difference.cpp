class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int maxi = 0;
        
        map < int , int > mp;
        
        for ( int i = 0 ; i < arr.size() ; i++ ) {
            
            if ( mp[arr[i] - difference] ) {
                
                mp[arr[i]] = mp[arr[i]-difference] + 1;
                
            } else mp[arr[i]] = 1;
            
            maxi = max( maxi , mp[arr[i]] );
            
        }
        
        return maxi;
        
    }
};