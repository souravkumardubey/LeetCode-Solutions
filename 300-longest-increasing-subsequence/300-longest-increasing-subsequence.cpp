class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector < int > dp;
        
        dp.push_back(nums[0]);
        
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            
            if ( nums[i] > dp.back() ) {
                
                dp.push_back(nums[i]);
                
            }
            else {
                                // cout << *lower_bound(dp.begin(),dp.end(),nums[i]) << "\n";
                // int idx = lower_bound(dp.begin(),dp.end(),nums[i]) - nums.begin();
                // dp[idx-1] = nums[i];
                *lower_bound(dp.begin(),dp.end(),nums[i]) = nums[i];
                
            }
            
        }
        
        for ( auto i : dp ) cout << i << " ";
        cout << "\n";
        
        return dp.size();
        
    }
};