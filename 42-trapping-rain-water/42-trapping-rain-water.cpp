class Solution {
public:
    int trap(vector<int>& height) {
        
        int i = 0 , j = height.size() - 1;
        
        int maxLeft = 0, maxRight = 0, ans = 0;
        
        while ( i <= j ) {
            
            if ( height[i] <= height[j] ) {
                
                if ( height[i] > maxLeft ) maxLeft = height[i];
                else ans += maxLeft - height[i];
                i += 1;
                
            }
            else {
                
                if ( height[j] > maxRight ) maxRight = height[j];
                else ans += maxRight - height[j];
                j -= 1;
                
            }
            
        }
        
        return ans;
        
    }
};