class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
//      Similar problem : Count Subarrays With Score Less Than K
        
        long long ans = 0;
        
        int i = 0 , j = 0;
        
        long long currSum = 1 , currValue = 0;
        
        while ( i < nums.size() and j < nums.size() ) {
            
            currSum *= nums[j];
            
            currValue = currSum;
            
//             unless and untill our subarray values is >= k, we reduce it product by dividing the value by the elements of that particular subarray from the start.
            while ( i <= j and currValue >= k ) {
                
                currSum /= nums[i];
                i += 1;
                currValue = currSum;
                
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
