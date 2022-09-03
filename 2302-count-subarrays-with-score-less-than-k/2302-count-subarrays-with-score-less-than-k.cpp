class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long ans = 0;
        
        int i = 0 , j = 0;
        
        long long currSum = 0 , currValue = 0;
        
        while ( i < nums.size() and j < nums.size() ) {
            
            currSum += nums[j];
            
            currValue = currSum * ( j - i + 1 );
            
//             unless and untill our subarray values is >= k, we reduce it sum by subtracting the elements of that particular subarray from the start.
            while ( i <= j and currValue >= k ) {
                
                currSum -= nums[i];
                i += 1;
                currValue = currSum * (j - i + 1);
                
            }
            
//          if the value of a subarray is < k, that nthg but indirectly means that all its elements will definately be < k Hence we count all those elements as single length subarrays j - i + 1 elements.
            if ( currValue < k ) {
                
                ans += ( j - i + 1 );
                
            }
            
            j += 1;
            
        }
        
        return ans;
        
    }
};