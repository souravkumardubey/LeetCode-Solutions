class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector < int > ans;
        int n = arr.size();
        int i = 0, j = n - 1;
        
        while ( j - i + 1 > k ) {
            
            if ( abs(arr[i] - x) < abs(arr[j] - x) || ( abs(arr[i] - x) == abs(arr[j] - x) && arr[i] < arr[j] ) ) {
                
                j -= 1;
                
            } else {
                
                i += 1;
                
            }
            
        }
        
        for ( int k = i; k <= j; k++ ) ans.push_back(arr[k]);
        
        return ans;
        
    }
};