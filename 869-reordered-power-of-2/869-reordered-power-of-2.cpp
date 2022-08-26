class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string num = to_string(n);
        
        sort(num.begin(),num.end());
        for ( int i = 0 ; i < 32 ; i++ ) {
            
            string num2 = to_string(1 << i);
            sort(num2.begin(),num2.end());
            if ( num == num2 ) return true; 
            
        }
        
        return false;
        
    }
};