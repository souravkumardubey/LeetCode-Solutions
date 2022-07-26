class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map < char, int > um = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };

       int sum = um[s.back()];

       for ( int i = s.size() - 2 ; i >= 0 ; i-- ) {
           
           if ( um[s[i]] < um[s[i + 1]] ) {
               
               sum -= um[s[i]];
               
           }
           else {
               
               sum += um[s[i]];
               
           }
           
       }

       return sum;
        
    }
    
};