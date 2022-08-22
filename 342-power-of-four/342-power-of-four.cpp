class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if ( n % 3 != 1 ) return false;
        long long int i = ( n & ( n - 1 ) );
        
        if ( !i ) return true;
        return false;
    }
};