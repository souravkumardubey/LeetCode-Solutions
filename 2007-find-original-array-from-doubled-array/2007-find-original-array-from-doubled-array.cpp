class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        
        vector < int > vec;
        
        if ( arr.size() & 1 ) return vec;
        
        sort(arr.begin(),arr.end());
        
        unordered_map < int, int > mp;
        
        for ( auto i : arr ) mp[i] += 1;
        
        for ( int i = 0 ; i < arr.size() ; i++ ) {
            
            if ( !mp[arr[i]] ) {
                
                continue;
                
            }
            else if ( !mp[arr[i]*2] ) return {};
            else {
                
                mp[arr[i]] -= 1;
                mp[2 * arr[i]] -= 1;
                vec.push_back(arr[i]);
                // return vec;
                
            }
            
            
        }
        
        return vec;
        
    }
};