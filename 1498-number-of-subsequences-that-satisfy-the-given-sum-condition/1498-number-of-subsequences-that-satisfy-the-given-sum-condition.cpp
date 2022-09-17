class Solution {
    
public: 
    
    int numSubseq( vector < int >& nums, int target) {
        
        sort(nums.begin(), nums.end());
                
        int n = nums.size();
        vector < int > vec(n, 1);
        
        long long mod = 1e9 + 7;
        for ( int i = 1 ; i < n ; i++ ) vec[i] = ( vec[i - 1] * 2 ) % mod;

        int l = 0, r = n - 1, cnt = 0;
        
        while ( l <= r ) {
            
            if ( nums[l] + nums[r] <= target ) {
                
                cnt = ( cnt + vec[r - l] ) % mod;
                l += 1;
                continue;
                
            }
            
            r -= 1;
            
        }
        
        return cnt;
        
    }

};