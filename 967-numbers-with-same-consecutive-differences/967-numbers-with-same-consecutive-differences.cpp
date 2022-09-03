class Solution {
    
    vector < int > result;
    
    void getNumbers( int value , int n , int k ) {
        
        if ( n == 0 ) {
            
            result.push_back(value);
            return;
            
        } else {
            
            int val = value % 10;
        
            if ( val + k <= 9 ) {

                int newVal = value * 10 + ( val + k );
                getNumbers( newVal , n - 1 , k );

            }

            if ( k != 0 ) {

                if ( val >= k ) {

                    int newVal = value * 10 + ( val - k );
                    getNumbers( newVal , n - 1 , k );

                }

            }
            
        }

    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for ( auto i = 1 ; i <= 9 ; i++ ) {
            
            getNumbers(i , n - 1 , k);
            
        }
        
        return result;
        
    }
};